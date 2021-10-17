#include <iostream>
#include <cstdlib>
#include <ctime>

int login();
void blackjack();
void playerinterface();
int playercard();
int points{};
int AIpoints{};
int balance{ 100 };
int AIbalance{ 100 };
int AIcard();
int checkstop();

int main() {
	std::srand(std::time(nullptr));
	std::string again;
	if (login() == 0) {
		std::cout << "Too many attempst, program will terminate";
	}
	else {
		std::cout << "Welcome to BLACK JACK" << std::endl;
		std::cout << "Are you ready for you first card? (Yes/No)" << std::endl;
		std::string answer;
		std::cin >> answer;
		if (answer == "Yes" or answer == "yes") {
			do {
				blackjack();
				playerinterface();
				std::cout << "Want to go again? " << std::endl;
				std::cin >> again;
			} while (again != "No" or again != "no" or  balance > 0 or AIbalance > 0);
			if (balance == 200) {
				
				std::cout << "You won!" << std::endl;
			}
			else if (AIbalance == 200) {
				
				std::cout << " You lost! " << std::endl;
			}
		}
		else {
			std::cout << "Okay, goodbye" << std::endl;
			return 0;
		}
	}
	
		
}


int login() {
	std::string User[2]{ "Gambler1","5460" };
	int count= 1;
	std::string username;
	std::string password;
	do {
		std::cout << std::endl << "Attempt nr." << count << std::endl;
		std::cout << "Username: ";
		std::cin >> username;
		std::cout << "Password: ";
		std::cin >> password;
		count++;
	} while (username != User[0] and password != User[1] and count < 4);
	if (username == User[0] and password == User[1]) {
		return 1;
	}
	else {
		
		return 0;
	}
}

void blackjack() {
	char newcard;
	do {
			playercard();
			playerinterface();
			std::cout << "Do you want another card? (N to stop)" << std::endl;
			std::cin >> newcard;
	}while (newcard != 'N' and newcard != 'n' and points < 22);
	if (points > 21) {
			std::cout << "You lost 10 dollar, you are over 21" << std::endl;
			balance = balance - 10;
			AIbalance = AIbalance + 10;
			points = 0;
			AIpoints = 0;
			return;
	}
	else {
		do {
			AIcard();
		} while (checkstop() == 0);
		if (points > AIpoints) {
			balance = balance + 10;
			AIbalance = AIbalance - 10;
			std::cout << "You won 10 dollar, the AI got " << AIpoints << " and you got " << points << std::endl;
			points = 0;
			AIpoints = 0;
			return;
		}
		else if (AIpoints > 21) {
			balance = balance + 10;
			std::cout << "You won 10 dollar, the AI got " << AIpoints << " and you got " << points << std::endl;
			AIbalance = AIbalance - 10;
			points = 0;
			AIpoints = 0;
			return;
		}
		else {
			std::cout << "You lost 10 dollar, the AI got " << AIpoints << " and you got " << points << std::endl;
			balance = balance - 10;
			AIbalance = AIbalance + 10;
			points = 0;
			AIpoints = 0;
			return;
		}
	}


}
		
void playerinterface() {
	std::cout << "#####################" << std::endl;
	if (points < 10) {
	std::cout << "# Your points: 0" << points << "   #" << std::endl;
	}
	else {
		std::cout << "# Your points: " << points << "   #" << std::endl;
	}
	if (balance == 100) {
	std::cout << "# Your balance: " << balance << " #" << std::endl;
	std::cout << "# AI balance: " << AIbalance << "   #" << std::endl;
	}
	else if ( balance < 100) {
		std::cout << "# Your balance: 0" << balance << " #" << std::endl;
		std::cout << "# AI balance: " << AIbalance << "    #" << std::endl;
	}
	else if (balance > 100) {
		std::cout << "# Your balance: " << balance << "#" << std::endl;
		std::cout << "# AI balance: 0" << AIbalance << " #" << std::endl;
	}
	std::cout << "#####################" << std::endl;
}
int playercard() {
	int random;
	random = rand() % 13 + 1;
	if (random == 1) {
		std::cout << "You got an ACE!" << std::endl;
		std::cout << "Do you want 1 point or 11 points?" << std::endl;
		int choice;
		std::cin >> choice;
		if (choice == 1) {
			points = points + 1;
			return 1;
		}
		else if (choice == 11) {
			points = points + 11;
			return 11;
		}
	}
	else if(random == 11) {
		std::cout << "You got a jack" << std::endl;
		points = points + 10;
		return 10;
	}
	else if (random == 12) {
		std::cout << "You got a queen" << std::endl;
		points = points + 10;
		return 10;
	}
	else if (random == 13) {
		std::cout << "You got a king" << std::endl;
		points = points + 10;
		return 10;
	}
	else {
		std::cout << "You got " << random << std::endl;
		points = points + random;
		return random;
	}
	
}

int AIcard() {
	int random;
	random = rand() % 13 + 1;
	if (random == 1) {
		std::cout << "AI got an ACE!" << std::endl;
		
		if (AIpoints > 10) {
			AIpoints = AIpoints + 1;
			std::cout << "AI chose 1 point" << std::endl;
			return 1;
		}
		else  {
			AIpoints = AIpoints + 11;
			std::cout << "AI chose 1 point" << std::endl;
			return 11;
		}
	}
	else if (random == 11) {
		std::cout << "AI got a jack" << std::endl;
		AIpoints = AIpoints + 10;
		return 10;
	}
	else if (random == 12) {
		std::cout << "AI got a queen" << std::endl;
		AIpoints = AIpoints + 10;
		return 10;
	}
	else if (random == 13) {
		std::cout << "AI got a king" << std::endl;
		AIpoints = AIpoints + 10;
		return 10;
	}
	else {
		std::cout << "AI got " << random << std::endl;
		AIpoints = AIpoints + random;
		return random;
	}

}
int checkstop() {
	if (AIpoints >= points) {
		return 1;
	}
	else if (AIpoints < points){
		return 0;
	}
	else if (AIpoints > 21) {
		return 1;
	}
}