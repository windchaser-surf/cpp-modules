#include "Serializer.hpp"

Serializer::Serializer() {
    
}

Serializer::Serializer(const Serializer& old) {
    
    if (this == &old)
        return ;
}

Serializer& Serializer::operator=(const Serializer& old) {
    
    if (this == &old)
        return (*this);
    return (*this);
}

Serializer::~Serializer() {
    
}

uintptr_t Serializer::serialize(Data* ptr) {
    
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    
    return (reinterpret_cast<Data*>(raw));
}
