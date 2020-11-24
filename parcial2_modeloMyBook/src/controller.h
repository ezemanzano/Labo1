/*
 * controller.h
 *
 *  Created on: Nov 17, 2020
 *      Author: ezemanzano
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromPost(char* path , LinkedList* pArrayListPost);
int controller_loadFromTextUsers(char* path , LinkedList* pArrayListUsers);
int controller_sortUsers(void*thisA, void*thisB);
#endif /* CONTROLLER_H_ */
