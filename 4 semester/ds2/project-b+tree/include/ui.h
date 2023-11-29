
#ifndef PROJETO1_UI_H
#define PROJETO1_UI_H
#include "DataProcessing/data_processor.h"
#include "Remove/remove_manager.h"
#include "Search/search_manager.h"
#include "Update/update_manager.h"
#include "components.h"
/**
 * Stores data inserted by the user which has to be processed.
 */

/**
 * show the main options on screen for user to choose the operation to be done.
 */
void options();

/**
 * Receive from user the data necessary for insertion  and forwards it to
 * the data processing function
 */
void ui_insertion();

/**
 * Receive from user the name or the id for searching operation
 */
void ui_search();

/**
 * Receive from user the ID for removing operation.
 */
void ui_remove();

/**
 * Receive from user the ID for update operation.
 */
void ui_update();

#endif // PROJETO1_UI_H
