declare module "luhnjs" {
  export function isValid(input: string): boolean;
  export function generateCheckDigit(input: string): number;
  export function generateCheckDigitAsString(input: string): number;
  export function calculateLuhnRemainder(input: string): number;
}
