#include <iostream>
#include <vector>
#include <string>

class User {
	std::string name;
	int age;

public:
	User(const std::string& name, int age) : name(name), age(age) {}

	void print() const {
		std::cout << "Name: " << name << ", Age: " << age << std::endl;
	}

};

class Group {
	std::string title;
	int ageLimit;
	std::vector<User> users;

public:
	Group(const std::string& title, int ageLimit) : title(title), ageLimit(ageLimit) {}

	void appendUser(const User& user) {
		if (user.age > ageLimit) {
			users.push_back(user);
			std::cout << "User added to the group." << std::endl;
		}
		else {
			std::cout << "User cannot be added to the group." << std::endl;
		}
	}

	void removeUser() {
		users.clear();
		std::cout << "Users removed from the group." << std::endl;
	}

	void clear() {
		users.clear();
		std::cout << "Group cleared." << std::endl;
	}
};

int main() {
	User user1("John", 25);
	User user2("Alice", 18);
	User user3("Bob", 30);

	Group group("MyGroup", 20);
	group.appendUser(user1);
	group.appendUser(user2);
	group.appendUser(user3);

	std::cout << "Group members:" << std::endl;
	for (const User& user : group.users) {
		user.print();
	}

	group.removeUser();
	group.clear();

	return 0;
}