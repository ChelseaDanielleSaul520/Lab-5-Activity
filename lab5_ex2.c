#include <stdio.h>
#include <math.h>

// Function prototypes
int weighted_sum_ID(int ID_number);
int verify_sum(int sum_of_ID_number, int secret_key);
int check_id(int ID_number);

// Function to get the last digit of a number
int get_last_digit(int number) {
    return number % 10;
}

// Function to get the kth digit of a number
int get_last_kth_digit(int number, int k) {
    int f = number / (int)pow(10, k - 1);
    return get_last_digit(f);
}

// Function to calculate the weighted sum of the ID number digits
int weighted_sum_ID(int ID_number) {
    int sum = 0;
    for (int k = 1; k <= 8; k++) {
        sum += k * get_last_kth_digit(ID_number, k);
    }
    return sum;
}

// Function to verify the sum of ID numbers based on a single secret key
int verify_sum(int sum_of_ID_number, int secret_key) {
    if (sum_of_ID_number % secret_key == 0)
        return 1; // Valid
    else
        return 0; // Invalid
}

// Function to check if the ID number is valid based on the 'secret' verification scheme
int check_id(int ID_number) {
    int sum = weighted_sum_ID(ID_number);
    int secret_keys[] = {11, 13, 17};

    // Check validity with each secret key
    for (int i = 0; i < 3; i++) {
        if (verify_sum(sum, secret_keys[i]))
            return 1; // Valid
    }

    return 0; // Invalid
}

// Main function
int main() {
    int ID_number;

    printf("Enter your ID number: ");
    scanf("%d", &ID_number);

    if (check_id(ID_number)) {
        printf("You have a VALID ID!\n");
    } else {
        printf("You have an INVALID ID!\n");
    }
    
    return 0;
}