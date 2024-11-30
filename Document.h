#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "Primitive.h"

class Document {
public:
    Document(const std::string& name) : name(name) {}

    void addPrimitive(std::shared_ptr<Primitive> primitive) {
        primitives.push_back(primitive);
        std::cout << "В документ '" << name << "' добавлен примитив '" 
                  << primitive->getType() << "' с именем '" 
                  << primitive->getName() << "'." << std::endl;
    }

    void removePrimitive(const std::string& primitiveName, const std::string& primitiveType) {
        auto it = std::find_if(primitives.begin(), primitives.end(),
            [&](const std::shared_ptr<Primitive>& p) {
                return p->getName() == primitiveName && p->getType() == primitiveType;
            });

        if (it != primitives.end()) {
            std::cout << "Из документа '" << name << "' удален примитив '" 
                      << (*it)->getName() << "' типа '" 
                      << (*it)->getType() << "'." << std::endl;
            primitives.erase(it);
        } else {
            std::cout << "Примитив с именем '" << primitiveName 
                      << "' типа '" << primitiveType 
                      << "' не найден." << std::endl;
        }
    }

    void drawAllPrimitives() const {
        if (primitives.empty()) {
            std::cout << "В документе '" << name << "' нет примитивов." << std::endl;
            return;
        }
        for (const auto& primitive : primitives) {
            primitive->draw();
        }
    }

    void deleteAllPrimitives() {
        primitives.clear();
        std::cout << "Все примитивы удалены из документа '" << name << "'." << std::endl;
    }

    std::string getName() const {
        return name;
    }

private:
    std::string name;
    std::vector<std::shared_ptr<Primitive>> primitives;
};

#endif // DOCUMENT_H