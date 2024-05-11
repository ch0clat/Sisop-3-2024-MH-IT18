#include <stdio.h>
#include <string.h>
#include "action.h"

char* handle_gap(float distance) {
    if (distance < 3.5) {
        return "Gogogo";
    } else if (distance >= 3.5 && distance <= 10) {
        return "Push";
    } else if (distance > 10){
        return "Stay out of trouble";
    } else {
        return "Invalid info";
    }
}

char* handle_fuel(float fuel_percent) {
    if (fuel_percent > 80) {
        return "Push Push Push";
    } else if (fuel_percent >= 50 && fuel_percent <= 80) {
        return "You can go";
    } else if (fuel_percent < 50){
        return "Conserve Fuel";
    } else {
        return "Invalid info";
    }
}

char* handle_tire(int tire_wear) {
    if (tire_wear > 80) {
        return "Go Push Go Push";
    } else if (tire_wear >= 50 && tire_wear <= 80) {
        return "Good Tire Wear";
    } else if (tire_wear >= 30 && tire_wear < 50) {
        return "Conserve Your Tire";
    } else if (tire_wear < 30){
        return "Box Box Box";
    } else {
        return "Invalid info";
    }
}

char* handle_tire_change(char* current_tire) {
    if (strcmp(current_tire, "Soft") == 0) {
        return "Mediums Ready";
    } else if (strcmp(current_tire, "Medium") == 0) {
        return "Box for Softs";
    } else {
        return "Invalid tire type";
    }
}
