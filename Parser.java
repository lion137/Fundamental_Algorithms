package rpn;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;


public class Parser {
    public List<String> infixToPostfix(List<String> tokens){
        /* Takes an infix expression as a list of tokens and return post
         fix expression (as a list):
        (A + B) - (C * D) -> A B + C D * -
         */
        // Regular objects to match the tokens.
        String num = "(\\d+\\.\\d+)|(\\d+\\.)|(\\d+)"; //Floating point
        String oper = "\\+|-|\\*|\\/|";					//numbers
        HashMap<String, Integer> prec = new HashMap<String, Integer>();
        // Symbol table with operators precedence.
        prec.put("*", 3);
        prec.put("/", 3);
        prec.put("+", 2);
        prec.put("-", 2);
        prec.put("(", 1);
        ArrayList<String> postfixL = new ArrayList<>();
        ArrayList<String> operStack = new ArrayList<>();//Operators
        for (String token: tokens){
            if ( (token.matches(num))){
                postfixL.add(token);
            }
            else if (token.equals("(")) {
                operStack.add(0, token);
            }
            else if (token.equals(")")){
                String top = operStack.remove(0);
                while ( !(top.equals("(")) ) {
                    postfixL.add(top);
                    top = operStack.remove(0);
                }
            }
            else {
                while ( !(operStack.isEmpty()) &&
                        (prec.get(operStack.get(0))) >= prec.get(token)) {
                    postfixL.add(operStack.remove(0));
                }
                operStack.add(0, token);
            }
        }
        while (!(operStack.isEmpty())){
            postfixL.add(operStack.remove(0));
        }
        return postfixL;
    }
}
