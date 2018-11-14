type drink =
  | Coffee
  | Tea
  | EggCream;

let price = (d: drink): float =>
  switch (d) {
  | Coffee => 2.45
  | Tea => 3.78
  | EggCream => 1.67
  };

Js.log(price(Coffee)); /* outputs "2.45" */

let stringOfDrink = (drinkType: drink): string =>
  switch (drinkType) {
  | Coffee => "Coffee"
  | Tea => "Tea"
  | EggCream => "EggCream"
  };

Js.log(stringOfDrink(Tea)); /* outputs "Tea" */

/* Variant type with parameters */
type shirtSize =
  | Small
  | Medium
  | Large
  | XLarge(int);

let stringOfShirtSize = (size: shirtSize): string =>
  switch (size) {
  | Small => "S"
  | Medium => "M"
  | Large => "L"
  | XLarge(x) => String.make(x, 'X') ++ "L"
  };

let veryLarge = XLarge(2);
Js.log(stringOfShirtSize(veryLarge)); /* outputs "XXL" */
