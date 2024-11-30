#ifndef DOCUMENTCONTROLLER_H
#define DOCUMENTCONTROLLER_H

#include <iostream>
#include <memory>
#include <string>
#include "Document.h"

class DocumentController {
public:
    void createDocument() {
        std::cout << "Введите имя нового документа: ";
        std::string name;
        std::cin >> name;
        document = std::make_shared<Document>(name);
        std::cout << "Создан документ '" << document->getName() << "'." << std::endl;
    }

    void addPrimitive(const std::string& type) {
        if (document) {
            if (type == "circle") {
                double radius;
                std::cout << "Введите радиус круга: ";
                std::cin >> radius;
                document->addPrimitive(std::make_shared<Circle>("Circle", radius));
            } else if (type == "rectangle") {
                double width, height;
                std::cout << "Введите ширину и высоту прямоугольника: ";
                std::cin >> width >> height;
                document->addPrimitive(std::make_shared<Rectangle>("Rectangle", width, height));
            }
            // Добавьте другие типы примитивов здесь...
            else {
                std::cout << "Неподдерживаемый тип примитива." << std::endl;
            }
        } else {
            std::cout << "Документ не создан." << std::endl;
        }
    }

    void removePrimitive(const std::string& primitiveName, const std::string& primitiveType) {
        if (document) {
            document->removePrimitive(primitiveName, primitiveType);
        } else {
            std::cout << "Документ не создан." << std::endl;
        }
    }

    void deleteDocument() {
        if (document) {
            document->deleteAllPrimitives(); // Удаляем все примитивы перед удалением документа
            document.reset(); // Удаление указателя на документ
            std::cout << "Документ удален." << std::endl;
        } else {
            std::cout << "Документ не создан." << std::endl;
        }
    }

    void drawAllPrimitives() const {
        if (document) {
            document->drawAllPrimitives();
        } else {
            std::cout << "Документ не создан." << std::endl;
        }
    }

    bool isDocumentCreated() const { // Метод для проверки существования документа
        return document != nullptr;
    }

private:
    std::shared_ptr<Document> document; // Указатель на текущий документ
};

#endif // DOCUMENTCONTROLLER_H