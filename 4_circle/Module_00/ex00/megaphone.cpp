#include <iostream>
using namespace std;

int main(int as, char **av){
	int	i;
	
	i = 0;
	if (as != 2){
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (2);
	}
	while (av[1][i]){
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
			cout << (char) toupper(av[1][i]);
		else
			cout << av[1][i];
		i++;
	}
	cout << endl;
	return (EXIT_SUCCESS);
}
