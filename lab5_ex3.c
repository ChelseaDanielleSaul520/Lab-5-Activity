/* Exercise 3: Student or Faculty I.D.? (lab5_ex3.c)
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
    int f = number / (int) pow(10, k - 1);
    return get_last_digit(f); //EDIT THIS
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

/**
 * Verify the sum of id numbers based on ONE single secret key.
 * 
 * @param sum_of_ID_number sum of the ID number to be tested
 * @param secret_key represents the number used as secret key used by security office
 * @return returns 1 if the sum is divisble by secret key. Otherwise, 0
 */
int verify_sum(int sum_of_ID_number, int secret_key) {
    return sum_of_ID_number % secret_key == 0; //EDIT THIS
}

/**
 * validates whether the entered id_number is valid or not based on the 'secret' verfiication scheme. 
 * It uses weighted_sum_ID, verify_sum functions to validate it.
 * 
 * @param ID_number ID number to be tested
 * @return returns 1 if ID number is valid on at least 1 of the secret key. Otherwise, 0
 */
int check_id(int ID_number, int secret_key) {
    int num_digit = 0;
    int temp = ID_number;
    while (temp > 0) {
        temp /= 10;
        num_digit++;
    }

    int sum = weighted_sum_ID(ID_number, num_digit);
    int is_valid = verify_sum(sum, secret_key);

    if (is_valid) {
        printf("You have a VALID ID!\n");
    } else {
        printf("You have an INVALID ID!\n");
    }

    return is_valid; //EDIT THIS
}


/**
 * checks whether the verified ID is a student or faculty. 
 * 
 * @param ID_number ID number to be tested
 * @return returns -1 if it's invalid, 1 if it's student, and 2 if it's faculty
 */
int type_of_id(int ID_number) {
    int secret_key = 11;
    int type = check_id(ID_number, secret_key);
    return type; //EDIT THIS
}

// Begin main function
int main(void) {
    int userID, idCode;

	printf("Enter your ID number: ");
	scanf("%d", &userID);
	idCode = type_of_id(userID);

	if (idCode == -1) printf("You have an INVALID ID!\n");
	else if (idCode == 1) printf("You have a STUDENT ID!\n");
	else if (idCode == 2) printf("You have a FACULTY ID!\n");

	return 0;
}