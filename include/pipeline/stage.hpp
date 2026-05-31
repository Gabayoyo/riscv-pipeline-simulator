#pragma once

// generic base class for pipeline stages to inherit from
// mandates execute() function for each stage to implement, which will be called in the main pipeline tick function
class Stage {
    public:
        virtual void execute() = 0;
};