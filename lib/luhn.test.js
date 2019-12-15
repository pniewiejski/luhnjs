const assert = require("assert");
const luhn = require("./luhn");

describe("Check if provided input is correct using Luhn's algorithm", () => {
    it("Should verify that input is correct for a correct input", () => {
        // given
        const inputToVerify = "79927398713";
        // when
        const isValid = luhn.isValid(inputToVerify);
        // then
        assert.equal(isValid, true);
    });

    it("Should verify that input is NOT correct for a incorrect input", () => {
        // given
        const inputToVerify = "79927398712";
        // when
        const isValid = luhn.isValid(inputToVerify);
        // then
        assert.equal(isValid, false);
    });
});

describe("Generate a check digit using Luhn's algorithm", () => {
    it("Should generate a correct check digit", () => {
        // given
        const expectedCheckDigit = 3;
        const numberForWhichToCalculateCheckDigit = "7992739871";
        // when
        const checkDigit = luhn.generateCheckDigit(numberForWhichToCalculateCheckDigit);
        // then
        assert.equal(checkDigit, expectedCheckDigit);
    });

    it("Should generate a correct check digit of 0 for case when Luhn's remainder is 0", () => {
        // given
        const expectedCheckDigit = 0;
        const numberForWhichToCalculateCheckDigit = "123";
        // when
        const checkDigit = luhn.generateCheckDigit(numberForWhichToCalculateCheckDigit);
        // then
        assert.equal(checkDigit, expectedCheckDigit);
    });

    it("Should generate a correct check digit of type number", () => {
        // given
        const expectedCheckDigit = 2;
        const numberForWhichToCalculateCheckDigit = "110494";
        // when
        const checkDigit = luhn.generateCheckDigit(numberForWhichToCalculateCheckDigit);
        // then
        assert.equal(checkDigit, expectedCheckDigit);
        assert.ok(typeof checkDigit === "number");
    });

    it("Should generate a correct check digit of type string", () => {
        // given
        const expectedCheckDigit = "9";
        const numberForWhichToCalculateCheckDigit = "110424";
        // when
        const checkDigit = luhn.generateCheckDigitAsString(
            numberForWhichToCalculateCheckDigit
        );
        // then
        assert.equal(checkDigit, expectedCheckDigit);
        assert.ok(typeof checkDigit === "string");
    });
});

describe("calculateLuhnRemainder", () => {
    it("Should calculate the correct value", () => {
        // given
        const input = "79927398710";
        const expectedRemainder = 7;
        // when
        const calculatedRemander = luhn.calculateLuhnRemainder(input);
        // then
        assert.equal(calculatedRemander, expectedRemainder);
    });
});

describe("When invalid data is provided", () => {
    describe("generateCheckDigit", () => {
        it("Should throw an exception in case when input doesn't contain only numbers", () => {
            // given
            const numberForWhichToCalculateCheckDigit = "123asdf";
            // when
            const checkDigitGenerationAction = () =>
                luhn.generateCheckDigit(numberForWhichToCalculateCheckDigit);
            // then
            assert.throws(checkDigitGenerationAction, { name: "TypeError" });
        });

        it("Should throw an exception in case when input contains spaces", () => {
            // given
            const numberForWhichToCalculateCheckDigit = "123 235";
            // when
            const checkDigitGenerationAction = () =>
                luhn.generateCheckDigit(numberForWhichToCalculateCheckDigit);
            // then
            assert.throws(checkDigitGenerationAction, { name: "TypeError" });
        });
    });

    describe("isValid", () => {
        it("Should throw an exception in case when input doesn't contain only numbers", () => {
            // given
            const numberToCheck = "123asdf";
            // when
            const checkDigitGenerationAction = () => luhn.isValid(numberToCheck);
            // then
            assert.throws(checkDigitGenerationAction, { name: "TypeError" });
        });

        it("Should throw an exception in case when input contains spaces", () => {
            // given
            const numberToCheck = "123 235";
            // when
            const checkDigitGenerationAction = () => luhn.isValid(numberToCheck);
            // then
            assert.throws(checkDigitGenerationAction, { name: "TypeError" });
        });
    });

    describe("calculateLuhnRemainder", () => {
        it("Should throw an exception in case when input doesn't contain only numbers", () => {
            // given
            const input = "123asdf";
            // when
            const checkDigitGenerationAction = () => luhn.isValid(input);
            // then
            assert.throws(checkDigitGenerationAction, { name: "TypeError" });
        });

        it("Should throw an exception in case when input contains spaces", () => {
            // given
            const input = "123 235";
            // when
            const checkDigitGenerationAction = () => luhn.isValid(input);
            // then
            assert.throws(checkDigitGenerationAction, { name: "TypeError" });
        });
    });
});
