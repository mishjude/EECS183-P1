/**
 * focaccia.cpp
 *
 * <Mish Jude>
 * <mishmish>
 *
 * EECS 183: Project 1
 * Fall 2022
 *
 * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);



int main() {
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;

    // variable and constant definitions

    int loaves;
    int bagsOfFlour;
    int pkgOfYeast;
    double const PKG_YEAST_PER_LOAF = (7.0 / 9.0);
    int canistersOfSalt;
    double const SALT_CANISTERS_PER_LOAF = (15.0 / 48.0);
    int bottlesOfOliveOil;
    double const BOTTLES_OLIVEOIL_PER_LOAF = (37.0 / 625.0);
    double totalCost;
    double const COST_PER_BAG_OF_FLOUR = 2.69;
    double const COST_PER_CANISTER_OF_SALT = 0.49;
    double const COST_PER_PKG_OF_YEAST = 0.40;
    double const COST_PER_BOTTLE_OF_OLIVEOIL = 6.39;
    double flourCost;
    double saltCost;
    double yeastCost;
    double oliveOilCost;

    // ingredient quantity calculations

    loaves = ceil(people / 4.0);
    bagsOfFlour = ceil(loaves / 4.0);
    pkgOfYeast = ceil(PKG_YEAST_PER_LOAF * loaves);
    canistersOfSalt = ceil(SALT_CANISTERS_PER_LOAF * loaves);
    bottlesOfOliveOil = ceil(BOTTLES_OLIVEOIL_PER_LOAF * loaves);

    // costs for ingredients and total shopping bill cost calculations

    flourCost = (bagsOfFlour * COST_PER_BAG_OF_FLOUR);
    yeastCost = (pkgOfYeast * COST_PER_PKG_OF_YEAST);
    saltCost = (canistersOfSalt * COST_PER_CANISTER_OF_SALT);
    oliveOilCost = (bottlesOfOliveOil * COST_PER_BOTTLE_OF_OLIVEOIL);
    totalCost = flourCost + saltCost + yeastCost + oliveOilCost;

    // outputs in shopping list format

    cout << "You need to make: " << loaves << pluralize(" loaf", " loaves", loaves) << " of focaccia" << endl << endl;
    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;
    cout << bagsOfFlour << pluralize(" bag", " bags", bagsOfFlour) << " of flour" << endl;
    cout << pkgOfYeast << pluralize(" package", " packages", pkgOfYeast) << " of yeast" << endl;
    cout << canistersOfSalt << pluralize(" canister", " canisters", canistersOfSalt) << " of salt" << endl;
    cout << bottlesOfOliveOil << pluralize(" bottle", " bottles", bottlesOfOliveOil) << " of olive oil" << endl << endl;

    //rounds total cost of ingredients to the nearest cent
    cout << "Total expected cost of ingredients: $" << floor(totalCost * 100 + 0.5) / 100 << endl << endl << endl;
    cout << "Have a great party!" << endl;

    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
