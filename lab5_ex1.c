/* Exercise 2: I.D. Verification (lab5_ex2.c)
*/

#include <stdio.h>
#include <math.h>

/**
 * gets the final digit of a number
 * 
 * @param number the number to be checked on
 * @return returns the final digit
 */
int get_last_digit(int number) {

	return number % 10; //EDIT THIS
}

/**
 * gets the kth digit of a number. 
 * Uses the ff formula:
 *		f(number, k) = (int) number / (int) 10^(k-1),
 *		last_kth_digit = get_last_digit( f(number, k) )
 * 
 * @param number the number to be checked on
 * @param k represents order of the digit. 1 represents ones digit. 2 means tens digits, so on.
 * @return returns the kth digit of number
 */
int get_last_kth_digit(int number, int k) {
	int f = number / (int)pow(10, k - 1);
    return get_last_digit(f);
}

/**
 * accumulates the products of k and get_last_kth_digit functions. 
 * Let k be an iterator from the last digit to the first digit. 
 * It performs the step 2 in the verification scheme.
 * 
 * @param ID_number the ID number to be tested
 * @param num_digits represents the total amount of digits of the ID_numbers to test on. The count starts from the last digit.
 * @return returns the weighted sum of the individial digits
 */
int weighted_sum_ID(int ID_number, int num_digits) {
	int weighted_sum = 0;

	for (int k = num_digits; k > 0; k--) {
        int kth_digit = get_last_kth_digit(ID_number, k);
        weighted_sum += k * kth_digit;
	}
	return weighted_sum; //EDIT THIS
}

// Begin main function
int main (void) {
	int userID;

	printf("Enter your ID number: ");
	scanf("%d", &userID);

	if (check_id(userID)) {
		printf("You have a VALID ID!\n");
	}
	else {
		printf("You have an INVALID ID!\n");
	}
	
	return 0;
}