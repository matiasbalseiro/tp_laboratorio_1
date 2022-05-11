#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define LEN_NAME 51
#define LEN_CODE 10
#define LEN_FORCED_CHARGE 5

struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}typedef Passenger;

/// @brief  To indicate that all position in the array are empty,
/// 		this function put the flag (isEmpty) in TRUE in all
/// 		position of the array
/// @param list Pointer to array of passenger
/// @param len Array length
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initPassengers(Passenger *list, int len);

/// @brief add in a existing list of passengers the values received as parameters
///		   in the first empty position
/// @param list Pointer to array of passenger
/// @param len Array length
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param flycode
/// @return Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int addPassenger(Passenger *list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight);
/// @brief find a Passenger by Id en returns the index position in array.
/// @param list Pointer to array of passenger
/// @param len Array length
/// @param id
/// @return Return passenger index position or (-1) if [Invalid length or
///         NULL pointer received or passenger not found]
int findPassengerById(Passenger *list, int len, int id);

/// @brief Remove a Passenger by Id (put isEmpty Flag in 1)
/// @param list Pointer to array of passenger
/// @param len Array length
/// @param id
/// @return Return (-1) if Error [Invalid length or NULL pointer or if can't
///         find a passenger] - (0) if Ok
int removePassenger(Passenger *list, int len, int id);

/// @brief
/// @param list Pointer to array of passenger
/// @param len Array length
/// @param id
/// @return
int modifyPassenger(Passenger *list, int len, int id);

/// @brief Sort the elements in the array of passengers, the argument order
///        indicate UP or DOWN order
/// @param list Pointer to array of passenger
/// @param len Array length
/// @param order
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortPassengers(Passenger *list, int len, int order);

/// @brief print the content of passengers array
/// @param list Pointer to array of passenger
/// @param length Array length
/// @return
int printPassengers(Passenger *list, int length);

/// @brief Sort the elements in the array of passengers, the argument order
///        indicate UP or DOWN order
/// @param list Pointer to array of passenger
/// @param len Array length
/// @param order [1] indicate UP - [0] indicate DOWN
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortPassengersByCode(Passenger *list, int len, int order);

/// @brief
/// @param list Pointer to array of passenger
/// @param len Array length
/// @param id
/// @return
int findIndexById(Passenger *list, int len, int id);

/// @brief
/// @param list Pointer to array of passenger
/// @param len Array length
/// @return
int findIndexByIsEmpty(Passenger *list, int len);

/// @param list Pointer to array of passenger
void printPassenger(Passenger list);

/// @brief
void printHeader();

/// @brief
/// @param list Pointer to array of passenger
/// @param len Array length
/// @return
int aPassenger(Passenger *list, int len);

/// brief
/// @param list Pointer to array of passenger
/// @return
int forcedCharge(Passenger *list);

int countPassengers(Passenger *list, int len);

float totalPrice(Passenger *list, int len);

float averagePrice(Passenger *list, int len);

int exceedAverage(Passenger *list, int len);

int reportPassenger(Passenger *list, int len);


#endif /* ARRAYPASSENGER_H_ */
