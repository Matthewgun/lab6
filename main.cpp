#include <iostream>
#include <memory>
#include "DocumentController.h"

void printMenu() {
    std::cout << "\nВыберите действие:\n";
    std::cout << "1. Создать документ\n";
    std::cout << "2. Добавить примитив\n";
    std::cout << "3. Отрисовать все примитивы\n";
    std::cout << "4. Удалить примитив\n";
    std::cout << "5. Удалить документ\n";
    std::cout << "6. Выход\n";
}

int main() {
    auto controller = std::make_shared<DocumentController>();

    while (true) {
        printMenu();
        
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                controller->createDocument();
                break;

            case 2: {
                std::cout << "Введите тип примитива (circle, rectangle): ";
                std::string type;
                std::cin >> type;
                controller->addPrimitive(type);
                break;
            }

            case 3:
                controller->drawAllPrimitives();
                break;

            case 4: { // Удаление примитива
                if (!controller->isDocumentCreated()) { // Проверка на существование документа
                    break; 
                }

                // Запрос имени и типа примитива для удаления
                std::cout << "Введите имя примитива для удаления: ";
                std::string nameToRemove;
                std::cin >> nameToRemove;

                // Запрос типа примитива для удаления
                std::cout << "Введите тип примитива для удаления: ";
                std::string typeToRemove; // Объявляем переменную
                std::cin >> typeToRemove; 

                controller->removePrimitive(nameToRemove, typeToRemove); 
                
                break; 
            }

            case 5: // Удаление документа
                controller->deleteDocument();
                break;

            case 6:
                return 0;

            default:
                std::cout << "Некорректный выбор.\n";
                break;
        }
    }
}