-- Keep a log of any SQL queries you execute as you solve the mystery.

-- O que já sabemos: Alguém roubou o CS50 duck, que estava na 'Humphrey Street'.
-- O crime ocorreu no dia 28 de julho de 2025.

-- Encontrar a descrição da cena do crime:
/*
SELECT year FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
-- Descobrimos que tem 3 testemunhas e todas mencionarm a padaria (bakery).
-- Descobrimos que o roubo aconteceu às 10:15am.
*/

-- Analisar os depoimentos das 3 testemunhas:
/*
SELECT name, transcript FROM interviews
WHERE day = 28 AND month = 7 AND year = 2025 AND transcript LIKE '%bakery%';
-- Descobrimos as 3 testemunhas: Ruth, Eugene, Raymond.
-- Ruth: Nos diz para olharmos as câmeras de segurança da padaria.
-- Eugene: Diz que o ladrão estava sacando dinheiro na Rua Leggett antes do roubo
-- Raymond: Disse que o ladrão conversou com alguém depois de sair da padaria. O ladrão estava planejando pegar
-- o próximo voo saindo fiftyville no dia seguinte.
-- Vamos começar com as câmeras da padaria.
--*/

-- Analisar as câmeras da padaria:
/*
SELECT activity, people.license_plate, people.name, minute FROM bakery_security_logs
JOIN people ON bakery_security_logs.license_plate = people.license_plate
WHERE day = 28 AND month = 7 AND hour = 10 AND minute BETWEEN 15 AND 25;
-- Deixei tudo numa tabela com a atividade dos carros, as placas e os
-- nomes das pessoas, conectando a tabela people
-- com a tabela bakery_security_logs.
-- Temos até agora 8 suspeitos: Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana e Kelsey.
*/

-- Analisar os registros do ATM na rua Leggett:
/*
SELECT bank_accounts.account_number, amount, bank_accounts.person_id, people.name FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE atm_location = 'Leggett Street' AND day = 28 AND month = 7 AND year = 2025 AND transaction_type = 'withdraw';
-- Descobrimos mais coisa e podemos filtrar nossa lista de suspeitos, dando baixa em quatro deles.
-- Os suspeitos que sobraram, ou seja, estavam sacando dinheiro na rua Leggett são: Bruce, Luca, Iman e Diana.
*/

-- Analisar os registros telefônicos:
/*
SELECT call.phone_number, call.name, receive.phone_number, receive.name, duration FROM phone_calls
JOIN people AS call ON phone_calls.caller = call.phone_number
JOIN people AS receive ON phone_calls.receiver = receive.phone_number
WHERE day = 28 AND month = 7 AND year = 2025 AND duration <= 60;
-- Descobrimos alguns números de ligações que duraram menos de 60s.
-- Dentre essas ligações estavam alguns de nossos suspeitos. Três deles.
-- Luca, era um deles, mas estava recebendo a ligação, então podemos desconsiderá-lo.
-- Sobraram dois: Bruce, ligando para Robin, e Diana, ligando para Philip.
*/

-- Analisar os primeiros voos do dia seguinte:
/*
SELECT destination_airport_id, hour, minute, id FROM flights
WHERE day = 29 AND month =7 AND year = 2025
AND origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville')
ORDER BY hour ASC;
-- Aqui eu descobri mais coisas, o primeiro voo do dia 29 é o voo de id = 36 e
*/

-- Analisar o voo de id = 36:
/*
SELECT origin_airport_id, destination_airport_id, day, month, year, hour, minute FROM flights
WHERE id = 36;
-- Descobrimos que esse voo vai para o aeroporto de id = 4.
*/

-- Analisar o aeroporto de id = 4:
/*
SELECT city, full_name, abbreviation FROM airports
WHERE id = 4;
-- Descobrimos que ele vai para New York City, para o aeroporto de LaGuardia (LGA).
*/

-- Vamos agora analisar os passageiros do voo de id = 36:
/*
SELECT people.passport_number, seat, people.name FROM passengers
JOIN people ON passengers.passport_number = people.passport_number
WHERE flight_id = 36;
-- Dentre nossos suspeitos, apenas uma pessoa estava nesse voo, e essa pessoa é o ladrão do pato.
-- BRUCE!!!!!!!!!!!!!!!!!!!! Ou seja, o ajudador era ROBIN!!!!!!
*/

