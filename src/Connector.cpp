#include <iostream>
#include "Shell.h"

using namespace std;

void Connector::amp(queue<string>& q, bool status) {
    q.pop();
    if (!status) {
        if (!q.empty()) {
            if (q.front() == "test") {
                while (!q.empty() && !isCon(q.front())) {
                    q.pop();
                }
            }

            else if (q.front() == "[") {
                while (!q.empty() && q.front() != "]") {
                   q.pop();
                }
                if (!q.empty() && q.front() == "]") {
                    q.pop();
                }
            }

            else if (q.front() == "(") {
                par.push("(");
                q.pop();
                popPar(q);
            }

            else if (!isCon(q.front())) {
                q.pop();
            }
        } 
    }
}

void Connector::orr(queue<string>& q, bool status) {
    q.pop();
    if (status) {
        if (q.size() != 0) {
            if (q.front() == "test") {
                while (!q.empty() && !isCon(q.front())) {
                    q.pop();
                }
            }

            else if (q.front() == "[") {
                while (!q.empty() && q.front() != "]") {
                        q.pop();
                }
                if (!q.empty() && q.front() == "]") {
                    q.pop();
                }
            }

            else if (!isCon(q.front())) {
                q.pop();
            }
        }
    }
}

void Connector::semi(queue<string>& q) {
    q.pop();
}

void Connector::popPar(queue<string>& q) {
    // if par empty, then paren are good
    while (!par.empty() && !q.empty()) {
        // push to stack, pop from queue
        if (q.front() == "(") {
            par.push("(");
            q.pop();
        }
        // pop from stack and queue
        else if (q.front() == ")") {
            par.pop();
            q.pop();
        }
        else {
            q.pop();
        }
    }
}
