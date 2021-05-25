/****************************************************************************/
/*                                                                          */
/* This file contains the interface functions                               */
/* you should use for the wet ex 1                                          */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/* File Name : library.h                                                   */
/*                                                                          */
/****************************************************************************/

#ifndef _234218_WET1
#define _234218_WET1

#ifdef __cplusplus
extern "C" {
#endif

/* Return Values
 * ----------------------------------- */
typedef enum {
    SUCCESS = 0,
    FAILURE = -1,
    ALLOCATION_ERROR = -2,
    INVALID_INPUT = -3
} StatusType;

<<<<<<< HEAD

=======
/*
>>>>>>> 90e93661cf8f3ca466205794d0e17d8b6e66f1ef
void *Init();

StatusType AddCarType(void *DS, int typeID, int numOfModels);

StatusType RemoveCarType(void *DS, int typeID);

StatusType SellCar(void *DS, int typeID, int modelID);

StatusType MakeComplaint(void *DS, int typeID, int modelID, int t);

StatusType GetBestSellerModelByType(void *DS, int typeID, int * modelID);

StatusType GetWorstModels(void *DS, int numOfModels, int *types, int *models);

void Quit(void** DS);
<<<<<<< HEAD

=======
*/
>>>>>>> 90e93661cf8f3ca466205794d0e17d8b6e66f1ef
#ifdef __cplusplus
}
#endif

#endif    /*_234218_WET1 */