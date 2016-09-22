#include "../include/RESTServerApplication.h"
#include "../include/PizzaHandler.h"
#include <iostream>

int main(int argc, char** argv) {

    std::cerr << "\nStarting server...";

    RouteMap router = {
            {"/pizza", handler<PizzaHandler>()}
    };

    RESTServerApplication app{router};
    return app.run(argc, argv);
}