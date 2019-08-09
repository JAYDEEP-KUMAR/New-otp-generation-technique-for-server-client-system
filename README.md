# New-otp-generation-technique-for-server-client-system
Developing New Pseudorandom Number Generator for Secure Application and applying it in a banking scenario

A one-time password or pin (OTP) is a password for completing a transaction, on a computer system or other digital device which cannot be same if it is generated more than one time. We will generate OTP with the concept of pseudorandom number and OTP generation method which is generally a Hash Chain and some other mathematical Algorithms proposed by Leslie Lamport.


Truly random number sequences are those in which it’s theoretically impossible to predict the next digit in the sequence based on the digits up to a given point. As all the existing algorithms to generate random numbers are merely algorithms which means at some or the other point the next number can be predicted. So, this concept has given rise to the term pseudo random number. Pseudo random numbers are those in which the sequence will repeat but after a large range which can’t be easily estimated. Pseudorandom number generators are used for session key generation, simulation and games, and other applications that need long bit sequences which possess a lot of qualities like large cycle length and uniform distribution over the range of number domain and the iterations which it is revolved around. This project includes concept of the new random number generator, its statistical testing result and related proofs. In today’s existing bank cards which are being used in all types of online transactions the only feature that provides security from frauds is the OTP which will be generated at the end of transaction. This project aims at using pseudo random numbers to create OTPs for online transactions without any data discrepancies. 
