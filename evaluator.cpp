//
//  evaluator.cpp
//  Project03
//
//  Created by Calvin Yin on 11/29/14.
//  Copyright (c) 2014 Calvin Yin. All rights reserved.
//

#include "evaluator.h"

queue<Token> infixToPostfix(queue<Token> infixExpression){
    queue<Token> postFix;
    
    while (!infixExpression.empty()){
        
        Token temp = infixExpression.front();
        queue<Token> q;
        infixExpression.pop();
        
        cout << temp << endl;
    
        if(temp.isNumber()){
            postFix.push(temp);
            //Write [enqueue] the operand [to the result queue]
            cout << "qwert" << endl;
        }
        else if (temp.op() == leftParen){
            postFix.push(temp);
            
        }else if (temp.op() == add || temp.op() == subtract || temp.op() == multiply || temp.op() == divide || temp.op() == power ){
            cout << "asdf" << endl;
            if(temp.op() == add || temp.op() == subtract){
                cout << postFix.front() << endl;
                while (postFix.empty() || postFix.front().op() != leftParen){
                    q.push(postFix.front());
                    postFix.pop();
                    cout << postFix.front() << endl;
                }
            }else if(temp.op() == multiply || temp.op() == divide){
                while (postFix.empty() || postFix.front().op() != leftParen || postFix.front().op() != add || postFix.front().op() != subtract){
                    q.push(postFix.front());
                    postFix.pop();
                }
            }else if(temp.op() == power){
                while (postFix.empty() || postFix.front().op() != leftParen || postFix.front().op() != add || postFix.front().op() != subtract || postFix.front().op() != multiply || postFix.front().op() != divide){
                    q.push(postFix.front());
                    postFix.pop();
                }
            }
            while (!q.empty()){
                postFix.push(q.front());
                q.pop();
            }
            postFix.push(temp);
        
        }else if(temp.op() == rightParen){
            queue<Token> qute;
            while (postFix.front().op() != leftParen) {
                if(postFix.empty())
                    throw string("unbalenced");
                qute.push(postFix.front());
                postFix.pop();
            }
        }
        
    }
    
    
    return postFix;
    
}

double evaluatePostfix(queue<Token> expression){
    return 0.0;
}
