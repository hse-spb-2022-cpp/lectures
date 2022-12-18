enum class Major { AMIS, ADAAI };

struct Person {
    std::string first_name, last_name;
    Major major;

    Person(std::string first_name_, std::string last_name_, Major major_)
        : first_name(std::move(first_name_))
        , last_name(std::move(last_name_))
        , major(std::move(major_)) {}
};
