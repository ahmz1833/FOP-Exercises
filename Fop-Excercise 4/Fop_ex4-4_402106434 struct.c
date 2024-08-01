///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 4               //
//     Part 4 "Hallelujah Mountain"      //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

#define uint            unsigned int                        // For abbreviation :)
#define MAX_TERMS       200                                 // Max number of monomials in each polynomial
#define IS_ZERO(x)      ((x < 0.0001) && (x > -0.0001))     // Declare a macro for checking a double variable is zero or not

/* Create a datatype struct Polynomial for our polynomials ! :) */
struct Polynomial
{
    int terms;              // Number of monomials (terms) in polynomial
    double coef[MAX_TERMS]; // Array of Coefficients (Zarayeb in persian) of monomials
    uint exp[MAX_TERMS];    // Array of Exponents (Degree or power) of each monomial
};

/* Declare Prototype of our functions */
struct Polynomial takeDerivative(struct Polynomial, uint);  // Returns the derivative of order i of a polynomial (Recursive)
struct Polynomial scanPolynomial(uint);                     // Inputs a Polynomial with n terms (in special format)
struct Polynomial stdPolynomial(struct Polynomial);         // Standardizes a Polynomial (Aljebric sum of same monomials and Sort)
void printPolynomial(struct Polynomial);                    // Prints a Polynomial (in special and standard format)

/* Our Main Fuction */
int main(void)
{
    uint n = 0, i = 0;  // n: number of terms of polynomial   ,,    i: order of derivative
    scanf("%u%u", &n, &i);      // Scan n & i

    struct Polynomial my_poly = scanPolynomial(n); // Input the Polynomial with n terms
    struct Polynomial result_poly = takeDerivative(my_poly, i); // Take derivative of order i
    printPolynomial(result_poly); // Print the result polynomial

    return 0;
}

/***************** Function : takeDerivative(P,i) ****************/
/* Returns the derivative of order i of a polynomial (Recursive) */
struct Polynomial takeDerivative(struct Polynomial P, uint order)
{
    if(order == 0) return P;   // :)))

    struct Polynomial P_Prime;
    P_Prime.terms = 0;

    if(P.terms == 0) return P_Prime; // If the input P is empty -> return empty  :)))

    // We know that the derivative does not affect the Sum :)
    // Iterate over terms in P -> and then take derivative of each term and put it in P_Prime
    for(uint i = 0; i < P.terms; i++)
    {
        //WE CONSIDERED  P(x) IS ALREADY STANDARDED AND SORTED DESCENDING
        if(P.exp[i] == 0) break; // when reaches to a constant number, break the loop (end of P(x))

        // Take derivative of monomial -> put it in P_Prime 
        P_Prime.coef[i] = P.exp[i] * P.coef[i];
        P_Prime.exp[i] = P.exp[i] - 1;
        P_Prime.terms++;
    }

    // If we need to higher order of derivative -> Take them recursively
    if(order > 1) return takeDerivative(P_Prime, order - 1);
    // Else : return P_prime
    else return P_Prime; 
}

/****************** Function : scanPolynomial(n) *****************/
/*      Inputs a Polynomial with n terms (in special format)     */
struct Polynomial scanPolynomial(uint termsNum)
{
    struct Polynomial poly; // Declare the poly struct variable :)
    poly.terms = termsNum; // Set the number of terms

    for(uint i = 0; i < termsNum; i++)   // Loop over monomials
        scanf("%lf*x^%u", &poly.coef[i], &poly.exp[i]); // Get the i-th monomial in special format [+/-]k*x^n
    
    // Another Method to get each monomial in lines below :)
        /*
        char sign, tmp;
        do scanf("%c", &sign); while (sign != '-' && sign != '+'); // Wait to read a (+/-)
        scanf("%lf", &poly.coef[i]); // Scan the coefficient
        if(sign == '-') poly.coef[i] *= -1.0f; // If the sign is - -> coef *= -1;
        do scanf("%c", &tmp); while (tmp != '*'); // Wait to read a *
        do scanf("%c", &tmp); while (tmp != 'x'); // Wait to read a x
        do scanf("%c", &tmp); while (tmp != '^'); // Wait to read a ^
        scanf("%d", &poly.exp[i]); // Scan the power (exp) of x (order of this term)
        */
    
    return stdPolynomial(poly); // Returns standarded form of the scanned polynomial
}

/****************** Function : stdPolynomial(P) ******************/
/*   Standardizes P (Aljebric sum of same monomials and Sort)    */
struct Polynomial stdPolynomial(struct Polynomial poly)
{
    struct Polynomial stdPoly;
    stdPoly.terms = 0;

    // Determine Max degree of the poly
    uint maxDeg = 0;
    for(uint i = 0; i < poly.terms; i++) if(poly.exp[i] > maxDeg) maxDeg = poly.exp[i];

    // Iterate from Max Degree to zero -> and search to see if it's found in poly
    for(int deg = maxDeg; deg >= 0; deg--)
    {
        // Declare a flag to determine if at least one monomial of this order (deg) is already put in stdPoly
        uint curDegExistFlag = 0;
        // Search poly to see if a monomial of order (deg)  found in poly
        for(uint i = 0; i < poly.terms; i++)
        {
            if((poly.exp[i] == deg) && !IS_ZERO(poly.coef[i])) // If found, (and it is not zero)
            {
                if(curDegExistFlag) // IF we have a same degree term, in stdPoly
                {
                    stdPoly.coef[stdPoly.terms-1] += poly.coef[i]; // Aljebic sum with it

                    // If after Aljebric sum , it become zero -> FULL REMOVE IT FROM stdPoly
                    if(IS_ZERO(stdPoly.coef[stdPoly.terms-1]))
                    {
                        stdPoly.coef[stdPoly.terms-1] = 0;
                        stdPoly.exp[stdPoly.terms-1] = 0;
                        stdPoly.terms--;
                        curDegExistFlag = 0;
                    }
                }
                else // If it is a new degree term and we have to put it in stdPoly
                {
                    curDegExistFlag = 1;
                    stdPoly.terms++;
                    stdPoly.exp[stdPoly.terms-1] = deg;
                    stdPoly.coef[stdPoly.terms-1] = poly.coef[i];
                }
            }
        }
    }
    return stdPoly; // Returns the standardized P(x)
}

/***************** Function : printPolynomial(P) *****************/
/*     Prints a Polynomial (in special and standard format)      */
void printPolynomial(struct Polynomial P)
{ 
    P = stdPolynomial(P); // Stantardize P(x)

    // If there isn't any monomial -> We have P(x) = 0.00
    if(P.terms == 0) printf("0.00"); 

    // Iterate over the monomials
    for(uint i = 0; i < P.terms; i++)
    {
        if(IS_ZERO(P.coef[i])) continue; // If the coefficient is zero -> Don't Print it!

        if(P.exp[i] == 0) // If the order (power) of this monomial is zero
            printf("%+.2lf", P.coef[i]);  // Only Print the constant number (not  k*x^0)
        else // Else : (the order is not zero)
            printf("%+.2lf*x^%u", P.coef[i], P.exp[i]);  // Print in format [+/-]k*x^n
    }
}