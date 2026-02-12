void front_ultra() {

    digitalWrite(front_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(front_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(front_trigPin, LOW);

    duration_1 = pulseIn(front_echoPin, HIGH, 30000); // 30 ms timeout

    if (duration_1 > 0) {
      front_distance = duration_1 * 0.0343 / 2;
    }
  }

void ground_ultra() {

  digitalWrite(ground_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ground_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ground_trigPin, LOW);

  duration_2 = pulseIn(ground_echoPin, HIGH, 30000); // 30 ms timeout

  if (duration_2 > 0) {
    ground_distance = duration_2 * 0.0343 / 2;
  }
}

