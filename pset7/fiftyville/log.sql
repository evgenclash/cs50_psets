-- Keep a log of any SQL queries you execute as you solve the mystery.

--Find info about the crime in the crime_scene_reports
 select * from crime_scene_reports where month = 7 and day = 28 and street = 'Chamberlin Street';
 
--  create a table with suspects based on records of the courthouse security_log how entered the courthouse before the thief
create table suspects as select id, license_plate, month, day, hour, minute, activity from courthouse_security_logs where day = 28 and hour < 11 and activity = 'entrance';
-- delete all the person that left the courthouse before 10 am
delete from suspects where license_plate in (select license_plate from courthouse_security_logs where month = 7 and day = 28 and hour < 10 and activity = 'exit');
-- delete persons that left the courthouse before 10;15 am
delete from suspects where hour = 10 and minute > 15;

-- select all the interviews that mentioned 'courthouse'
select * from interviews where transcript like '%courthouse%' and month = 7; 
-- select all the atm withdraws on fifer street
select * from atm_transactions where month = 7 and day = 28 and atm_location = 'Fifer Street' and transaction_type = 'withdraw';
-- find the flight that the thief took
select city from airports where id = (select destination_airport_id from flights where month = 7 and day = 29 and origin_airport_id = (
select * from flights where month = 7 and day = 29 and origin_airport_id = (select id from airports where city = 'Fiftyville') order by hour limit 1);

-- select all the passengers passports
SELECT passport_number from passengers where flight_id = 36;

-- Create a table of suspects and include all the info from people table and courthouse info
create table suspects as select courthouse_security_logs.id, courthouse_security_logs.license_plate, courthouse_security_logs.day, courthouse_security_logs.hour, courthouse_security_logs.minute, people.name, courthouse_security_logs.activity, people.phone_number, passport_number from people 
join courthouse_security_logs on courthouse_security_logs.license_plate = people.license_plate
where day = 28 and hour < 11 and activity = 'entrance';

-- Select all the people info that made the withdraw on fifer street on 28 of july
select * from people where id in(select person_id from bank_accounts where account_number in(
select * from atm_transactions where month = 7 and day = 28 and atm_location = 'Fifer Street' and transaction_type = 'withdraw');

-- Calls of all of the suspects
select * from phone_calls where caller in (select phone_number from suspects) and month = 7 and day = 28 and duration > 60;

-- The THEIF!! 
select * from suspects where name in
(select name from people where id in(select person_id from bank_accounts where account_number in(
select account_number from atm_transactions where month = 7 and day = 28 and atm_location = 'Fifer Street' and transaction_type = 'withdraw')));

-- Knowing that Ernest is the thief we check to whom he was calling 
SELECT * FROM people where phone_number = (select receiver from phone_calls where caller = '(367) 555-5533' and duration = 45);
