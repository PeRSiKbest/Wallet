#include "menu.h"
#include <iostream>
#include <memory>
#include <string>

void Menu::showMenu() {
    std::cout << "\n������� ���������� ������������� ���������\n";
    std::cout << "1. �������� �������/�����\n";
    std::cout << "2. ��������� �������/�����\n";
    std::cout << "3. �������� ������\n";
    std::cout << "4. �������� �������\n";
    std::cout << "5. �������� �������\n";
    std::cout << "6. ������������ �����\n";
    std::cout << "7. ������������ ���-3 ��������\n";
    std::cout << "8. ������������ ���-3 ���������\n";
    std::cout << "9. ��������� ������ � ����\n";
    std::cout << "0. �����\n";
    std::cout << "�������� �����: ";
}

void Menu::run(FinanceManager& manager) {
    while (true) {
        showMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // ������������ ���������� ������ ����� ������

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            std::string name, type;
            double balance;
            std::cout << "������� ��� ��������/�����: ";
            std::getline(std::cin, name);
            std::cout << "������� ��� (debit/credit): ";
            std::getline(std::cin, type);
            std::cout << "������� ��������� ������: ";
            std::cin >> balance;
            std::cin.ignore();
            auto wallet = std::make_shared<Wallet>(name, type, balance);
            manager.addWallet(wallet);
            std::cout << "�������/����� ��������(�).\n";
            break;
        }
        case 2: {
            std::string name;
            double amount;
            std::cout << "������� ��� ��������/����� ��� ����������: ";
            std::getline(std::cin, name);
            std::cout << "������� ����� ����������: ";
            std::cin >> amount;
            std::cin.ignore();
            manager.depositToWallet(name, amount);
            break;
        }
        case 3: {
            std::string name, category, description;
            double amount;
            std::cout << "������� ��� ��������/����� ��� �������: ";
            std::getline(std::cin, name);
            std::cout << "������� ��������� �������: ";
            std::getline(std::cin, category);
            std::cout << "������� ����� �������: ";
            std::cin >> amount;
            std::cin.ignore();
            std::cout << "������� �������� �������: ";
            std::getline(std::cin, description);
            manager.addExpense(name, Expense(category, amount, description));
            break;
        }
        case 4:
            manager.showBalances();
            break;
        case 5:
            manager.showExpenses();
            break;
        case 6: {
            std::string period;
            std::cout << "������� ������ ������ (day/week/month): ";
            std::getline(std::cin, period);
            manager.generateReport(period);
            break;
        }
        case 7: {
            std::string period;
            std::cout << "������� ������ ��� ���-3 �������� (week/month): ";
            std::getline(std::cin, period);
            manager.generateTopExpenses(period, 3);
            break;
        }
        case 8: {
            std::string period;
            std::cout << "������� ������ ��� ���-3 ��������� (week/month): ";
            std::getline(std::cin, period);
            manager.generateTopCategories(period, 3);
            break;
        }
        case 9: {
            std::string filename;
            std::cout << "������� ��� ����� ��� ���������� �������: ";
            std::getline(std::cin, filename);
            manager.saveReportsToFile(filename);
            break;
        }
        default:
            std::cout << "�������� �����. ����������, ���������� �����.\n";
        }
    }
}