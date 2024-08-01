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
#define MAX_TERMS       200                                 // Max number of monomials in polynomial
#define IS_ZERO(x)      ((x < 0.0001) && (x > -0.0001))     // Declare a macro for checking a double variable is zero or not

// A Useful Macro for Debug :)
#define _DEBUG_(fmt,val1,val2,val3)  printf("\n\tDEBUG (Line %d): ", __LINE__); printf(fmt,val1, val2,val3)

int terms;                // Number of monomials (terms) in polynomial
double coef[MAX_TERMS];   // Array of Coefficients (Zarayeb in persian) of monomials
uint expon[MAX_TERMS];    // Array of Exponents (Degree or power) of each monomial

/* Declare Prototype of our functions */
void scanPolynomial(uint);      // Inputs Polynomial with n terms (in special format)
void stdPolynomial(void);       // Standardizes Polynomial (Aljebric sum of same monomials and Sort)
void takeDerivative(uint);      // Returns the derivative of order i of polynomial (Recursive)
void printPolynomial(void);     // Prints Polynomial (in special and standard format)

/* Our Main Fuction */
int main(void)
{
    uint n = 0, i = 0;      // n: number of terms of polynomial   ,,    i: order of derivative
    scanf("%u%u", &n, &i);  // Scan n & i

    scanPolynomial(n); // Input the Polynomial with n terms
    stdPolynomial();   // Standardize the polynomial
    takeDerivative(i); // Take derivative of order i
    printPolynomial(); // Print the result polynomial

    return 0;
}

/***************** Function : takeDerivative(P,i) ****************/
/*  Returns the derivative of order i of polynomial (Recursive)  */
void takeDerivative(uint order)
{
    if(order == 0) return;   // :)))
    uint newTerms = 0; // number of terms in derivated poly

    // We know that the derivative does not affect the Sum :)
    // Iterate over terms in P(x) -> and then take derivative of each term and put it in P(x)
    for(uint i = 0; i < terms; i++)
    {
        //WE CONSIDERED  P(x) IS ALREADY STANDARDED AND SORTED DESCENDING
        if(expon[i] == 0) break; // when reaches to a constant number, break the loop (end of P(x))

        // Take derivative of monomial 
        coef[i] *= expon[i];
        expon[i] -= 1;
        newTerms++;
    }
    terms = newTerms;

    // If we need to higher order of derivative -> Take them recursively
    if(order > 1) takeDerivative(order - 1);
    // Else : return
    else return; 
}

/****************** Function : scanPolynomial(n) *****************/
/*        Input Polynomial with n terms (in special format)      */
void scanPolynomial(uint termsNum)
{
    terms = termsNum; // Set the number of terms

    for(uint i = 0; i < terms; i++)   // Loop over monomials
        scanf("%lf*x^%u", &coef[i], &expon[i]); // Get the i-th monomial in special format [+/-]k*x^n

    return; // Return; P(x) Scanned!
}

/****************** Function : stdPolynomial(P) ******************/
/*   Standardizes P (Aljebric sum of same monomials and Sort)    */
void stdPolynomial(void)
{
    int stdTerms = 0;       // Number of monomials (terms) in standarded polynomial
    double stdCoef[MAX_TERMS];  // Array of Coefficients (Zarayeb in persian) of monomials in standarded P(x)
    uint stdExp[MAX_TERMS];     // Array of Exponents (Degree or power) of each monomial in standarded P(x)

    uint maxDeg = 0;
    for(uint i = 0; i < terms; i++) if(expon[i] > maxDeg) maxDeg = expon[i]; // Determine Max degree of the poly
    for(uint i = 0; i < MAX_TERMS; i++) { stdCoef[i] = 0;  stdExp[i] = 0; }  // Initialize stdCoef & stdExp

    // Iterate from Max Degree to zero -> and search to see if it's found in poly
    for(int deg = maxDeg; deg >= 0; deg--)
    {
        // Search poly to see if a monomial of order (deg)  found in poly
        for(uint i = 0; i < terms; i++)
        {
            if((expon[i] == deg) && !IS_ZERO(coef[i])) // If found, (and it is not zero)
            {
                stdCoef[stdTerms] += coef[i]; // Aljebic sum with it
                stdExp[stdTerms] = deg;
            }
        }
        // If it is a not-zero term and we have to keep it in stdPoly
        if(!IS_ZERO(stdCoef[stdTerms])) stdTerms++;
    }

    // Copy stdPoly to global Poly
    for(int i = 0; i < MAX_TERMS; i++)
    {
        expon[i] = (i < stdTerms) ? stdExp[i] : 0;
        coef[i] = (i < stdTerms) ? stdCoef[i] : 0;
    }
    terms = stdTerms;
    return; // Returns; P(x) standardized !
}

/***************** Function : printPolynomial(P) *****************/
/*     Prints a Polynomial (in special and standard format)      */
void printPolynomial()
{
    stdPolynomial();

    // If there isn't any monomial -> We have P(x) = 0.00
    if(terms == 0) printf("0.00"); 

    // Iterate over the monomials
    for(uint i = 0; i < terms; i++)
    {
        if(IS_ZERO(coef[i])) continue; // If the coefficient is zero -> Don't Print it!

        if(expon[i] == 0) // If the order (power) of this monomial is zero
            printf("%+.2lf", coef[i]);  // Only Print the constant number (not  k*x^0)
        else // Else : (the order is not zero)
            printf("%+.2lf*x^%u", coef[i], expon[i]);  // Print in format [+/-]k*x^n
    }
}