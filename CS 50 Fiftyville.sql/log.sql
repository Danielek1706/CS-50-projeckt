-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Search crime scene report on Humphrey Street dated July 28, 2021.
SELECT * FROM crime_scene_reports WHERE street = 'Humphrey Street';

--The report reveals that the theft of the CS50 duck took place on 6 July 2021 at 10:15am at a bakery on Humphrey Street. The report also mentions that three witnesses who were present at the time were interviewed.

-- Search for suspects linked to bakery thefts.
SELECT * FROM interviews WHERE transcript LIKE '%bakery%';

--Three witnesses were present in the bakery at the time of the theft:
--Ruth - watched footage from the bakery, Eugene - was at the ATM in Leggett, Raymond - had a short phone call.

--Check witness Ruth.
SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;

--Check license plate.
SELECT p.name, bsl.activity, bsl.license_plate, bsl.year, bsl.month, bsl.day, bsl.hour, bsl.minute
FROM bakery_security_logs bsl
JOIN people p ON p.license_plate = bsl.license_plate
WHERE bsl.year = 2021 AND bsl.month = 7 AND bsl.day = 28 AND bsl.hour = 10 AND bsl.minute BETWEEN 15 AND 25;

--Check witness Eugene - ATM.
SELECT * FROM atm_transactions
WHERE atm_location = 'Leggett Street'
And year = 2021 AND month = 7 AND day = 28;

--Name of wtihdraws form ATM.
SELECT a.*, p.name
FROM atm_transactions a
JOIN bank_accounts b ON a.account_number = b.account_number
JOIN people p ON b.person_id = p.id
WHERE a.atm_location = 'Leggett Street' AND a.year = 2021 AND a.month = 7 AND a.day = 28;

-- Check witness Raymond - Phone call.
SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

--The names of callers.
SELECT p.name, pc.caller, pc.receiver, pc.year, pc.month, pc.day, pc.duration
FROM phone_calls pc
JOIN people p ON pc.caller = p.phone_number
WHERE pc.year = 2021 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60;

--Explore aipports and found Fiftyville.
SELECT * FROM airports WHERE city = 'Fiftyville';

-- List of names of passengers on the flight to Fiftyville.
SELECT name
FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = (
    SELECT id
    FROM flights
    WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = (
        SELECT id
        FROM airports
        WHERE city = "Fiftyville"
    )
    ORDER BY hour, minute
    LIMIT 1
);

-- Phone number to Bruce.
SELECT phone_number FROM people WHERE name  = "Bruce";
-- Phone number to Bruce is: (367) 555-5533.

--Recipient who answered the number from Bruce.
SELECT name FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28
AND duration < 60 AND caller = "(367) 555-5533");

