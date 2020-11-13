#include <iostream>
#include <cmath>
#include <vector>

bool true_check(std::string question){
	char x[100] = {0};
	std::cout << question << std::endl << "y/n" << std::endl;
	std::cin >> x;

	if (x[0] == 'y' || x[0] == 'Y'){
	return true; 
	}
	if (x[0] == 'n' || x[0] == 'N'){
	return false;
	}
	std::cout << "Please give a valid imput anon" << std::endl;
	return true_check(question);
}

void vector_printer(std::vector<std::string> vector_name_1, std::vector<int> vector_name_2){
	for (int i = 0; i < vector_name_1.size(); ++i){
		std::cout << i+1 << ". : " << vector_name_1[i] << " : " << vector_name_2[i] << "Kr" << std::endl; 
	}
}

int soda_selector(std::vector <int> stock_vector){
	int x;
	std::cin >> x;
	if (x < 1 || x > 5){
	    std::cout << "Please give a valid imput anon" << std::endl;
	    return soda_selector(stock_vector);
	}
    if (stock_vector[x-1] == 0 ){
        std::cout << "This soda type is empty" << std::endl;
        return soda_selector(stock_vector);
    }
	    return (x-1);
}

int coin_sorter(int y){
    
    if (y == 0){
        std::cout << y << std::endl;
        return (y);
    }
    if (y%20 == 0){
        std::cout << "20" << std::endl;
        return coin_sorter (y-20);
    }
    if (y%10 == 0){
        std::cout << "10" << std::endl;
        return coin_sorter (y-10);
    }
    if (y%5 == 0){
        std::cout << "5" << std::endl;
        return coin_sorter (y-5);
    }
    std::cout << "1" << std::endl;
    return coin_sorter (y-1);

}		

int payment_function (int x){
    std::cout << "Amount to pay : " << x << std::endl;
    if (x <= 0){
        return (-x);
    }
    int payment; 
    std::vector<int> coin_vector;
    coin_vector = {1, 5 ,10, 20};
    std::cin >> payment;
    for (int i = 0; i <= coin_vector.size(); i++){
        if (payment == coin_vector[i]){
            return payment_function(x-coin_vector[i]);
        }    
    }   
    std::cout << "Please pay with real coins anon" << std::endl; 
    return payment_function(x);      
}

void sys_function (std::vector <int> &price_vector, std::vector <int> &stock_vector, std::vector <std::string> &soda_vector, int k){
    
    std::cout << "which vector do you want to configure? " << std::endl << "1. : " << "Price" << std::endl << "2. : " << "Stock" << std::endl << "3. : " << "Type" << std::endl;
    int x, y, z;
    std::string n;
    if (k == 0){
        std::cin >> x;
    }
 
	if (x < 1 || x > 3){
	    std::cout << "Please give a valid imput anon" << std::endl;
	    return sys_function(price_vector, stock_vector, soda_vector, k);
	}
    
    while (x == 1){
        std::cout << "which price do you want to configure? " << std::endl;
        for (int i = 0; i < price_vector.size(); i++){
            std::cout << i+1 << ". : " << soda_vector[i] << " : " << price_vector[i] << " : " << stock_vector[i] << std::endl;
        }
        std::cin >> y;
        if (y < 1 || y > price_vector.size()){
            std::cout << "Please give a valid imput anon" << std::endl;
            return sys_function(price_vector, stock_vector, soda_vector, 1);
        }
        std::cout << "what do you want to sett the price to? " << std::endl;
        std::cin >> z;
        price_vector[y-1] = z;
        std::cout << "The new price of "<< soda_vector[y-1] << " is " << price_vector[y-1] << std::endl;
        if (true_check("Do you want to contine to configure the machine? ") == true){
            return sys_function(price_vector, stock_vector, soda_vector, 0);
        }
        return;
    }

    while (x == 2){
        std::cout << "which stock do you want to configure? " << std::endl;
        for (int i = 0; i < stock_vector.size(); i++){
            std::cout << i+1 << ". : " << soda_vector[i] << " : " << price_vector[i] << " : " << stock_vector[i] << std::endl;
        }
        std::cin >> y;
        if (y < 1 || y > stock_vector.size()){
            std::cout << "Please give a valid imput anon" << std::endl;
            return sys_function(price_vector, stock_vector, soda_vector, 1);
        }
        std::cout << "what do you want to sett the stock to? " << std::endl;
        std::cin >> z;
        stock_vector[y-1] = z;
        std::cout << "The new stock of "<< soda_vector[y-1] << " is " << stock_vector[y-1] << std::endl;
        if (true_check("Do you want to contine to configure the machine? ") == true){
            return sys_function(price_vector, stock_vector, soda_vector, 0);
        }
        return;
    }

     while (x == 3){
        std::cout << "which name do you want to configure? " << std::endl;
        for (int i = 0; i < soda_vector.size(); i++){
            std::cout << i+1 << ". : " << soda_vector[i] << " : " << price_vector[i] << " : " << stock_vector[i] << std::endl;
        }
        std::cin >> y;
        if (y < 1 || y > soda_vector.size()){
            std::cout << "Please give a valid imput anon" << std::endl;
            return sys_function(price_vector, stock_vector, soda_vector, 1);
        }
        std::string m = soda_vector[y-1];
        std::cout << "what do you want the new name of " << m << " to be? " << std::endl;
        std::cin >> n;
        soda_vector[y-1] = n;
        std::cout << "The new name of "<< m << " is " << soda_vector[y-1] << std::endl;
        if (true_check("Do you want to contine to configure the machine? ") == true){
            return sys_function(price_vector, stock_vector, soda_vector, 0);
        }
        return;
    }
}

int main(){

    std::vector<std::string> soda_vector;
    std::vector<int> price_vector;
    std::vector<int> stock_vector;
    soda_vector = {"Cola", "Fanta", "Solo", "Urge", "Sprite"}; 
    price_vector = {25, 32, 22, 27, 35};
    stock_vector = {5, 5, 5, 5, 5};
    int x, hold;
    bool back;

    while (true){
        
        hold = true_check("Do you want to configure the machine? ");

        while(hold == true){
            sys_function(price_vector, stock_vector, soda_vector, 0);
            break;
        }
        
        while(hold == false){
            std::cout << "Which soda do you want?" << std::endl; 
            vector_printer (soda_vector, price_vector);

            int soda_choice = soda_selector(stock_vector);
            std::cout << "price : " << price_vector[soda_choice] << " "; 
            x = price_vector[soda_choice];

            coin_sorter (payment_function(x));

            stock_vector[soda_choice] -= 1;

            back = true_check ("Do you want to another purchase? ");

            if (back == false){
                break;
            }

        }   
    }
	return 0;
}