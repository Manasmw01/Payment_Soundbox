int firstline = 0;
void setup()
{
  Serial2.begin(9600);   // Setting the baud rate of GSM Module
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  Serial2.println("AT"); // AT Command to recieve a live SMS
  while (Serial2.available() > 0)
    Serial.write(Serial2.read());
  delay(100);
  Serial.println("AT+CMGF=1");
  while (Serial2.available() > 0)
    Serial.write(Serial2.read());
  delay(1000);
  Serial2.println("AT+CNMI=1,2,0,0,0"); // AT Command to recieve a live SMS
  while (Serial2.available() > 0)
    Serial.write(Serial2.read());
  delay(1000);
}
void loop()
{
  if (Serial2.available() > 0)
  {
    String mpm = Serial2.readStringUntil('\n');
    Serial.println(mpm);
    int mpmlen = mpm.length();
    Serial.println(mpmlen);
    int prev_index_val = 0, current_index_val = 0;
    if (firstline == 1)
    {
      current_index_val = mpm.indexOf("INR", prev_index_val);
      String one_at_a_time_str1 = mpm.substring(current_index_val + 4, current_index_val + 10);
      Serial.print(one_at_a_time_str1);
      Serial.println(".");
      firstline = 0;
    }
    if (mpm.startsWith("+CMT:"))
    {
      current_index_val = mpm.indexOf(',', prev_index_val);
      prev_index_val = current_index_val + 1;
      current_index_val = mpm.indexOf(',', prev_index_val);
      prev_index_val = current_index_val + 1;
      current_index_val = mpm.indexOf(',', prev_index_val);
      prev_index_val = current_index_val + 1;
      String one_at_a_time_str = mpm.substring(prev_index_val, prev_index_val + 5);
      Serial.println(one_at_a_time_str);
      firstline = 1;
      delay(100);
    }
    //    Serial.write(Serial2.read());
  }
  if (Serial.available() > 0)
    Serial2.write(Serial.read());
}
