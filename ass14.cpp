#include <iostream>
#include <limits>
using namespace std;

class NetworkData {
private:
    int latency;
    int signalStrength;
    int packetLoss;

public:
    NetworkData(int l=0, int s=0, int p=0) {
        latency = l;
        signalStrength = s;
        packetLoss = p;
    }

    void setData(int l, int s, int p) {
        latency = l;
        signalStrength = s;
        packetLoss = p;
    }

    int getLatency() const { return latency; }
    int getSignalStrength() const { return signalStrength; }
    int getPacketLoss() const { return packetLoss; }

    void display() const {
        cout << "\n--- Network Conditions ---\n";
        cout << "Latency: " << latency << " ms\n";
        cout << "Signal Strength: " << signalStrength << "\n";
        cout << "Packet Loss: " << packetLoss << " %\n";
    }
};

class Analyzer {
public:
    virtual string analyze(const NetworkData& data) = 0;
};

class RiskAnalyzer : public Analyzer {
public:
    string analyze(const NetworkData& data){
        double score = (data.getLatency() * 0.5) +(data.getPacketLoss() * 0.3) -(data.getSignalStrength() * 0.2);
        if (score > 70)
            return "FAILURE LIKELY";
        else if (score > 40)
            return "RISKY";
        else
            return "SAFE";
    }
};

class PaymentMode {
public:
    virtual void processPayment(double amount) = 0;
};

class OnlineUPI : public PaymentMode {
public:
    void processPayment(double amount){
        cout << "\n[ONLINE UPI]\n";
        cout << "Processing payment of Rs. " << amount << "...\n";
        cout << "Transaction Successful\n";
    }
};

class OfflineUPI : public PaymentMode {
public:
    void processPayment(double amount){
        cout << "\n[OFFLINE MODE - USSD (*99# Simulation)]\n";
        cout << "Dialing *99#...\n";
        cout << "Processing payment of Rs. " << amount << "...\n";
        cout << "Transaction Completed (Offline)\n";
    }
};

class Transaction {
private:
    double amount;
    string status;

public:
    Transaction(double amt) {
        amount = amt;
        status = "INITIATED";
    }

    void execute(PaymentMode* mode) {
        mode->processPayment(amount);
        status = "COMPLETED";
    }

    void showStatus() const {
        cout << "Transaction Status: " << status << endl;
    }
};

class PaymentSystem {
private:
    RiskAnalyzer analyzer;

    void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    double getValidAmount() {
        double amount;
        while (true) {
            cout << "\nEnter Amount: ";
            cin >> amount;
        if (cin.fail() || amount <= 0) {
                cout << "Invalid amount! Enter a positive number.\n";
                clearInput();
            } else {
                return amount;
            }
        }
    }

    int getValidRange(string msg, int min, int max) {
        int value;
        while (true) {
            cout << msg;
            cin >> value;

            if (cin.fail() || value < min || value > max) {
                cout << "Invalid input! Enter value between " << min << " and " << max << ".\n";
                clearInput();
            } else {
                return value;
            }
        }
    }

public:
    void startTransaction() {
        double amount = getValidAmount();
        int latency = getValidRange("Enter Latency (ms): ", 0, 1000);
        int signal = getValidRange("Enter Signal Strength (0-100): ", 0, 100);
        int loss = getValidRange("Enter Packet Loss (%): ", 0, 100);

        NetworkData data(latency, signal, loss);
        data.display();

        string prediction = analyzer.analyze(data);

        cout << "\nAI Prediction: " << prediction << endl;

        PaymentMode* mode;

        if (prediction == "SAFE")
            mode = new OnlineUPI();
        else
            mode = new OfflineUPI();

        Transaction txn(amount);
        txn.execute(mode);
        txn.showStatus();

        delete mode;
    }
};

int main() {
    PaymentSystem system;
    int choice;

    do {
        cout << "\n====== Hybrid UPI System ======\n";
        cout << "1. Make Transaction\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Enter numeric choice.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                system.startTransaction();
                break;
            case 2:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 2);

    return 0;
}
