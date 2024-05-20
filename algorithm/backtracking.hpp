#ifndef _BACK_TRACKING_H__
#define _BACK_TRACKING_H__
#include "common.h"
class BacktrackingProblem {
    public:
        static BacktrackingProblem& getInstance() {
            static BacktrackingProblem* ins = new BacktrackingProblem();
            return *ins;
        }

        void execute_problem(uint32_t problemId) {
            auto foundIt = m_problemMapping.find(problemId);
            if (foundIt == m_problemMapping.end()) {
                std::cout << "Could not find the problem in set" << std::endl;
                return;
            }
            foundIt->second();
        }

    protected:
        BacktrackingProblem() {
            initialize();
        }
        void initialize() {
            m_problemMapping = {
                { 0, hello_world }
            };
        }

    protected:
        static void hello_world() {
            std::cout << "Hello World" << std::endl;
        }

    protected:
        uint32_t m_problemId = 0;
        std::unordered_map<uint32_t, std::function<void()>> m_problemMapping;
};

#endif // _BACK_TRACKING_H__