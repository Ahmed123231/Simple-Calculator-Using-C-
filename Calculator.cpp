#include <iostream>

/**
 * @brief Prints the welcome message to the user.
 * 
 * This function prints a decorative line followed by a welcome message for the calculator.
 * It is called at the beginning of the program to greet the user.
 * 
 * @param void This function takes no parameters.
 * @return void This function does not return any value.
 */
void PrintWelcomeMessage(void)
{
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Welcome to the Easy Calculator!" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
}

/**
 * @brief Gets the first operand from the user.
 * 
 * This function prompts the user to enter the first operand for the calculation. It validates 
 * the input to ensure the user provides a valid numerical value. If the input is invalid, the 
 * function asks the user to enter the number again.
 * 
 * @param void This function takes no parameters.
 * @return double The first operand entered by the user.
 */
double GetFirstOperand(void)
{
    double Loc_doubleFirstOperand = 0.0;

    while(true)
    {
        std::cout << "Enter First Number: ";
        std::cin >> Loc_doubleFirstOperand;
        
        if(std::cin.fail())  /* Check if the input is valid */
        {
            std::cin.clear(); /* Clear the error flag */
            std::cin.ignore(10000, '\n'); /* Ignore invalid input */
            std::cout << "Invalid input! Please enter a valid number.\n";
        }
        else
        {
            return Loc_doubleFirstOperand; /* Return the valid input */
        }
    }
}

/**
 * @brief Gets the second operand from the user.
 * 
 * Similar to the GetFirstOperand function, this function prompts the user to enter the second operand. 
 * It validates the input to ensure the user provides a valid numerical value. 
 * 
 * @param void This function takes no parameters.
 * @return double The second operand entered by the user.
 */
double GetSecondOperand(void)
{
    double Loc_doubleSecondOperand = 0.0;

    while(true)
    {
        std::cout << "Enter Second Number: ";
        std::cin >> Loc_doubleSecondOperand;

        if(std::cin.fail())  /* Check if the input is valid */
        {
            std::cin.clear(); /* Clear the error flag */
            std::cin.ignore(10000, '\n'); /* Ignore invalid input */
            std::cout << "Invalid input! Please enter a valid number.\n";
        }
        else
        {
            return Loc_doubleSecondOperand; /* Return the valid input */
        }
    }
}

/**
 * @brief Gets a valid operator from the user.
 * 
 * This function prompts the user to choose a mathematical operator for the calculation 
 * (+, -, *, /). It validates that the input is a single character and one of the four 
 * valid operators. If the input is invalid, the function asks the user to enter the 
 * operator again.
 * 
 * @param void This function takes no parameters.
 * @return char The operator entered by the user.
 */
char GetOperator(void)
{
    std::string Loc_strOperator;
    
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Choose one of the following operators:" << std::endl;
    std::cout << "'+' for Addition" << std::endl;
    std::cout << "'-' for Subtraction" << std::endl;
    std::cout << "'*' for Multiplication" << std::endl;
    std::cout << "'/' for Division" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    while (true)
    {
        std::cout << "Enter Operator: ";
        std::cin >> Loc_strOperator;

        /* Check if the input is a single character and a valid operator */
        if (Loc_strOperator.length() == 1 && 
           (Loc_strOperator[0] == '+' || Loc_strOperator[0] == '-' || 
            Loc_strOperator[0] == '*' || Loc_strOperator[0] == '/'))
        {
            return Loc_strOperator[0]; /* Return the valid operator */
        }
        else
        {
            std::cout << "Invalid input! Please enter a valid operator.\n";
        }
    }
}


/**
 * @brief Performs the calculation based on the operands and operator.
 * 
 * This function takes the operand-fetching and operator-fetching functions as parameters. 
 * It retrieves the operands and the operator, performs the corresponding mathematical 
 * operation, and returns the result.
 * 
 * @param GetFirstOperand Function pointer to retrieve the first operand.
 * @param GetSecondOperand Function pointer to retrieve the second operand.
 * @param GetOperator Function pointer to retrieve the operator.
 * @return double The result of the calculation.
 */
double CalculateResult(double (*GetFirstOperand)(void), 
                       double (*GetSecondOperand)(void), 
                       char (*GetOperator)(void))
{
    double Loc_doubleFirstOperand = GetFirstOperand();
    double Loc_doubleSecondOperand = GetSecondOperand();
    char Loc_charOperator = GetOperator();
    double Loc_doubleResult = 0.0;

    /* Perform calculation based on the operator */
    switch (Loc_charOperator)
    {
        case '+':
            Loc_doubleResult = Loc_doubleFirstOperand + Loc_doubleSecondOperand;
            break;
        case '-':
            Loc_doubleResult = Loc_doubleFirstOperand - Loc_doubleSecondOperand;
            break;
        case '*':
            Loc_doubleResult = Loc_doubleFirstOperand * Loc_doubleSecondOperand;
            break;
        case '/':
            if(Loc_doubleSecondOperand == 0.0)
            {
                std::cout << "Error: Division by zero is undefined.\n";
            }
            else
            {
                Loc_doubleResult = Loc_doubleFirstOperand / Loc_doubleSecondOperand;
            }
            break;
        default:
            /* This case should not occur due to prior validation */
            break;
    }

    return Loc_doubleResult; /* Return the calculation result */
}

/**
 * @brief Prints the calculated result to the user.
 * 
 * This function calculates the result by calling the CalculateResult function and 
 * then prints the result to the console.
 * 
 * @param CalculateResult Function pointer to perform the calculation.
 * @return void This function does not return any value.
 */
void PrintResult(double (*CalculateResult)(double (*GetFirstOperand)(void), 
                                           double (*GetSecondOperand)(void), 
                                           char (*GetOperator)(void)))
{
    double Loc_doubleResult = CalculateResult(GetFirstOperand, GetSecondOperand, GetOperator);

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Result = " << Loc_doubleResult << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
}

/**
 * @brief Asks the user if they want to continue using the calculator.
 * 
 * This function prompts the user to enter 'y' to perform another calculation 
 * or 'n' to exit the program. It validates the input to ensure the user provides 
 * a valid response.
 * 
 * @param void This function takes no parameters.
 * @return bool Returns true if the user chooses to continue, false otherwise.
 */
bool AskToContinue(void)
{
    char Loc_charChoice = 0;
    
    while (true)
    {
        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> Loc_charChoice;

        if (Loc_charChoice == 'y' || Loc_charChoice == 'Y')
        {
            return true; /* Continue */
        }
        else if (Loc_charChoice == 'n' || Loc_charChoice == 'N')
        {
            return false; /* Exit */
        }
        else
        {
            std::cout << "Invalid input! Please enter 'y' to continue or 'n' to exit.\n";
        }
    }
}

/**
 * @brief Runs the calculator application.
 * 
 * This is the main function that runs the calculator. It calls all the necessary 
 * functions to perform calculations and asks the user if they want to continue 
 * after each operation. The program loops until the user chooses to exit.
 * 
 * @param void This function takes no parameters.
 * @return void This function does not return any value.
 */
void RunCalculator(void)
{
    bool Continue = true; /* Variable to track if the user wants to continue */

    PrintWelcomeMessage(); /* Display welcome message */

    while (Continue) /* Loop until the user decides to exit */
    {
        PrintResult(CalculateResult); /* Calculate and print the result */
        Continue = AskToContinue();   /* Ask if the user wants to continue */
    }

    std::cout << "Thank you for using the Easy Calculator! Goodbye!" << std::endl;
}

