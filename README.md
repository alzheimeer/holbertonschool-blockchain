<div align="center">
  <img width="600" height="350" src="https://live.staticflickr.com/1813/44050240512_1c763d73e2_b.jpg">
</div>

# Blockchain
Welcome to the Blockchain track ! \o/

The goal of this series of projects is to build a basic Blockchain/Cryptocurrency
entirely in C, and from scratch! Its going to be a lot of work, and were going to
go through this step by step.

![OS Linux](https://img.shields.io/badge/OS-Linux-blue.svg)
![distro Ubuntu](https://img.shields.io/badge/distro-Ubuntu-orange.svg)
![tecnology C](https://img.shields.io/badge/technology-C-green.svg)
![OpenSSL](https://img.shields.io/badge/toolkit-OpenSSL-brown.svg)
![Crypto](https://img.shields.io/badge/discipline-Crypto-yellow.svg)

## Topics
- What blockchain is
- How Cryptography works
- Data Structures concepts for Blockchain
- Block mining concepts for Blockchain

## Requirements
- Ubuntu 14.04 LTS
- C programs and functions will be compiled with gcc 4.8.4
- For this project, you will need to [Install the OpenSSL library](https://help.ubuntu.com/community/OpenSSL#Practical_OpenSSL_Usage) (if not already
  installed).


##0x00. Blockchain - Crypto
	0. SHA256  - Función que calcula el hash de una secuencia de bytes.
	1. EC_KEY creation -  Función que crea un nuevo par de claves EC
	2. EC_KEY to public key - Función que extrae la clave pública de una estructura opaca de EC_KEY.
	3. EC_KEY from public key -  Función que crea una estructura de EC_KEY dada una clave pública.
	4. EC_KEY - Save to file -  Función que guarda un par de llaves EC existente en el disco.
	5. EC_KEY - Load from file - Función que carga un par de llaves EC desde el disco.
	6. Signature - Función que firma un conjunto dado de bytes, utilizando una clave privada de EC_KEY dada
	7. Signature verification - Función que verifica la firma de un conjunto dado de bytes, utilizando una clave pública de EC_KEY dada
	8. Library - Escribe un makefile que compila todas las funciones anteriores.

##0x01. Blockchain - Data structures
	0. Create Blockchain - Función que crea una estructura Blockchain, y la inicializa.
	1. Create Block -  Función que crea una estructura de bloques y la inicializa.
	2. Delete Block - Función que elimina un bloque existente.
	3. Delete Blockchain - Función que elimina un Blockchain existente, junto con todos los bloques que contiene
	4. Hash Block - Función que calcula el hash de un bloque.
	5. Save Blockchain -  Función que serializa un Blockchain en un archivo
	6. Load Blockchain -  Función que deserializa un Blockchain de un archivo.
	7. Block validity - Función que verifica que un bloque es válido.

##0x02. Blockchain - Block mining
	0. Proof of work - función que comprueba si un hash dado coincide con una dificultad dada
	1. Block is valid v0.2 - Modificar la función block_is_valid para que revise que el hash de un bloque coincida con su dificultad
	2. Block mining - función que minas un bloque para insertarlo en el Blockchain
	3. Adjust difficulty - función que calcula la dificultad de asignar a un siguiente bloque potencial en el Blockchain.

##0x03. Blockchain - Transactions
	0. Create transaction output -  Función que asigna e inicializa una estructura de salida de transacción.
	1. Create unspent transaction output - Función que asigna e inicializa una estructura de salida de transacción no gastada
	2. Create transaction input - Función que asigna e inicializa una estructura de entrada de transacción
	3. Transaction ID -  Función que calcula la ID (hash) de una transacción
	4. Sign transaction input - Función que firma una entrada de transacción, dada la ID de transacción 
	5. Create transaction -  Función que crea una transacción.
	6. Transaction validation -  Función que comprueba si una transacción es válida
	7. Coinbase transaction - Función que crea una transacción de coinbase.
	8. Coinbase transaction validation - Función que comprueba si una transacción de coinbase es válida
	9. Delete transaction - Función que desalinea una estructura de transacción.
	10. Update Blockchain and Block creation/deletion 
		- Actualizar la función block_t *block_create - Su función ahora debe inicializar la lista de transacciones del bloque a una lista vinculada vacía.
		- Actualizar la función block_destroy - Su función ahora debe destruir la lista de transacciones del bloque.
	11. Create/delete list of unspent - Actualizar las funciones blockchain_create y blockchain_destroy respectivamente 
		- Cree y elimine la lista vinculada no gastada de salidas de transacción no gastadas.
	12. Update: Hash Block - Actualizar la función block_hash Para incluir la lista de transacciones en el hash de un bloque.
	13. Update: Block validation - Actualizar la función block_is_valid Para verificar que la lista de transacción de cada bloque es válida
	14. Update all unspent - Función que actualiza la lista de todas las salidas de transacción no gastadas, dada una lista de transacciones procesadas
	15. Update: Blockchain serialization & deserialization - Actualizar las funciones blockchain_serialize y blockchain_deserialize, para serializar la lista de transacciones de cada bloque.
	16. Blockchain library - Escriba un makefile que compila todas las funciones anteriores y las archiva en una biblioteca estática para uso futuro.

## Author
Edgar Quintero - <fogniebla@hotmail.com>  

## Licence
MIT 
\[ [Read](LICENSE) \]
