#include <iostream>
#include <fstream>
#include "examples/person.pb.h"

int main() {
    // 序列化
    Person person;
    person.set_name("Alice");
    person.set_id(123);
    person.set_email("alice@example.com");
    person.add_phones("123-4567");
    person.add_phones("987-6543");

    std::string serialized_data;
    person.SerializeToString(&serialized_data);
    std::cout << "Serialized data: " << serialized_data << std::endl;

    // 反序列化
    Person new_person;
    new_person.ParseFromString(serialized_data);
    std::cout << "Name: " << new_person.name() << std::endl;
    std::cout << "ID: " << new_person.id() << std::endl;

    return 0;
}
