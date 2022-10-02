uint16_t amount = 10000;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0)
  {
    String float_amt_string = Serial.readStringUntil('\n');
    float float_amt = float_amt_string.toFloat();
    amount = float_amt;
    Serial.println();
    Serial.println(float_amt);
    Serial.println(amount);
    int ones = amount % 10;
    int tens = (amount / 10) % 10;
    int hundreds = (amount / 100) % 10;
    int thousands = (amount / 1000) % 10;
    Serial.println(thousands);
    Serial.println(hundreds);
    Serial.println(tens);
    Serial.println(ones);
    if (thousands >= 1)
    {
      greaterthan0(thousands);
      Serial.print("Thousand ");
    }
    if (hundreds >= 1)
    {
      greaterthan0(hundreds);
      Serial.print("Hundred ");
    }
    if (tens >= 2)
    {
      if (amount > 100)
      {
        Serial.print("AND ");
      }
      greaterthan20(tens);
      if (ones > 0)
      {
        greaterthan0(ones);
      }
    }
    else if (tens > 0)
    {
      if (amount > 100)
      {
        Serial.print("AND ");
      }

      greaterthan10(ones);
    }
    else
    {
      if (amount > 100)
      {
        Serial.print("AND ");
      }

      if (ones > 0)
      {
        greaterthan0(ones);
      }
    }
    //        greaterthan20(hundreds);
    Serial.println();
  }
}

void greaterthan20(int hundredstemp)
{
  if (hundredstemp == 9)
    Serial.print("Ninety");
  else if (hundredstemp == 8)
    Serial.print("Eighty");
  else if (hundredstemp == 7)
    Serial.print("Seventy");
  else if (hundredstemp == 6)
    Serial.print("Sixty");
  else if (hundredstemp == 5)
    Serial.print("Fifty");
  else if (hundredstemp == 4)
    Serial.print("Forty");
  else if (hundredstemp == 3)
    Serial.print("Thirty");
  else if (hundredstemp == 2)
    Serial.print("Twenty");
  Serial.print(" ");
}

void greaterthan0(int tens_tmp)
{
  if (tens_tmp == 1)
    Serial.print("One");
  if (tens_tmp == 2)
    Serial.print("Two");
  if (tens_tmp == 3)
    Serial.print("Three");
  if (tens_tmp == 4)
    Serial.print("Four");
  if (tens_tmp == 5)
    Serial.print("Five");
  if (tens_tmp == 6)
    Serial.print("Six");
  if (tens_tmp == 7)
    Serial.print("Seven");
  if (tens_tmp == 8)
    Serial.print("Eight");
  if (tens_tmp == 9)
    Serial.print("Nine");
  Serial.print(" ");
}
void greaterthan10(int onestemp)
{
  if (onestemp == 0)
    Serial.println("Ten");
  if (onestemp == 1)
    Serial.println("Eleven");
  if (onestemp == 2)
    Serial.println("Twelve");
  if (onestemp == 3)
    Serial.println("Thirteen");
  if (onestemp == 4)
    Serial.println("Fourteen");
  if (onestemp == 5)
    Serial.println("Fifteen");
  if (onestemp == 6)
    Serial.println("Sixteen");
  if (onestemp == 7)
    Serial.println("Seventeen");
  if (onestemp == 8)
    Serial.println("Eighteen");
  if (onestemp == 9)
    Serial.println("Nineteen");
  Serial.print(" ");
}
