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

    it("Should generate a correct check digit of type number", () => {
        // given
        const expectedCheckDigit = "9";
        const numberForWhichToCalculateCheckDigit = "110424";
        // when
        const checkDigit = luhn.generateCheckDigitAsString(numberForWhichToCalculateCheckDigit);
        // then
        assert.equal(checkDigit, expectedCheckDigit);
        assert.ok(typeof checkDigit === "string");
    });

    it("Should generate a correct check digit", () => {
        // given
        const expectedCheckDigit = 3;
        const numberForWhichToCalculateCheckDigit = "7992739871";
        // when
        const checkDigit = luhn.generateCheckDigit(numberForWhichToCalculateCheckDigit);
        // then
        assert.equal(checkDigit, expectedCheckDigit);
    });

    describe("When invalid data is provided", () => {
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
});
