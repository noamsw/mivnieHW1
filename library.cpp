#include "library.h"
#include "unified.cpp"

void* Init()
{
    DSW* DS = new DSW();
    return (void*)DS;
}

StatusType AddCarType(void *DS, int typeID, int numOfModels)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    return (((DSW *)DS)->addCarType(typeID, numOfModels));
}

StatusType RemoveCarType(void *DS, int typeID)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    return (((DSW *)DS)->removeCarType(typeID));
}

StatusType SellCar(void *DS, int typeID, int modelID)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    return (((DSW *)DS)->sellCar(typeID,modelID));
}

StatusType MakeComplaint(void *DS, int typeID, int modelID, int t)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    return (((DSW *)DS)->MakeComplaint(typeID, modelID, t));
}

StatusType GetBestSellerModelByType(void *DS, int typeID, int * modelID)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    return (((DSW *)DS)->GetBestSellerModelByType(typeID, modelID));
}

StatusType GetWorstModels(void *DS, int numOfModels, int *types, int *models)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    return (((DSW *)DS)->GetWorstModels(numOfModels, types, models));
}

void Quit(void** DS)
{
    delete ((DSW *)(*DS));
    *DS = NULL;
}

