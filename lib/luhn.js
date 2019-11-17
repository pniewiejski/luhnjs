const napiLuhnImpl = require("../build/Release/luhncpp.node");

/**
 * Check if provided input is valid using Luhn's checksum algorithm
 *
 * @param {string} input input number to be verified in a form of a string of numbers
 * @returns {boolean}
 */
module.exports.isValid = input => {
    return napiLuhnImpl.isValid(input);
};

/**
 * Calulates a checkNumber using Luhn's algorithm
 *
 * Example:
 *  Assume an account number '1234' that will have a checkDigit added,
 *  making it of the form '1234x'. This function computes the 'x' digit.
 *
 * @param {string} input number for which checkDigit is to be calculated
 * in a form of a string of numbers
 * @returns {number}
 */
module.exports.generateCheckDigit = input => {
    return napiLuhnImpl.generateCheckDigit(input);
};

/**
 * The same as generateCheckDigit but returned checkDigit of type number
 * is converted to string type.
 *
 * @param {string} input number for which checkDigit is to be calculated
 * in a form of a string of numbers
 * @returns {string}
 */
module.exports.generateCheckDigitAsString = input => {
    const checkDigit = module.exports.generateCheckDigit(input);
    return checkDigit.toString();
};
