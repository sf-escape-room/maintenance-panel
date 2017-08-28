/*
 * Control code for the maintenance panel.
 */

const int OUTPUT_INDEX = 0;
const int INPUT_INDEX = 1;
const int number_of_channels = 3;
const int channels[][2] = {{10, 7}, {11, 8}, {12, 9}};
const int channel_check_delay = 500;
const int check_pin = 13;
const int lock_pin = 6;
bool correct_code = false;

void setup() {
  for(int index = 0; index < number_of_channels; index++) {
    pinMode(channels[index][OUTPUT_INDEX], OUTPUT);
    pinMode(channels[index][INPUT_INDEX], INPUT);
  }
  pinMode(check_pin, INPUT);
  pinMode(lock_pin, OUTPUT);
}

void loop() {
  control_lock();
  bool check = digitalRead(check_pin);
  if (check) {
    check_code();
  }
}

void control_lock() {
  if (correct_code) {
    lock_door();
  } else {
    unlock_door();
  }
}

void lock_door() {
  digitalWrite(lock_pin, HIGH);
}

void unlock_door() {
  digitalWrite(lock_pin, LOW);
}

void check_code() {
  bool should_unlock = true;
  for(int index = 0; index < number_of_channels; index++) {
    should_unlock = should_unlock && channel_connected(index);
  }
  correct_code = should_unlock; 
}

bool channel_connected(int index) {
  digitalWrite(channels[index][OUTPUT_INDEX], HIGH);
  delay(channel_check_delay);
  int connection = digitalRead(channels[index][INPUT_INDEX]);
  digitalWrite(channels[index][OUTPUT_INDEX], LOW);
  return (connection == HIGH);
}

