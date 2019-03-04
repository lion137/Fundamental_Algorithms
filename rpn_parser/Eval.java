package rpn;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;


public class Eval {
    public BigDecimal evalPostfix(List<String> expList){
        //operands stack
        ArrayList<BigDecimal> operStack = new ArrayList<BigDecimal>();
        String num = "(\\d+\\.\\d+)|(\\d+\\.)|(\\d+)"; //Floating point
        for (String token: expList){
            if (token.matches(num)){
                BigDecimal b1 = new BigDecimal(token);
                operStack.add(0, b1);
            }
            else {
                BigDecimal oper2 = operStack.remove(0);
                BigDecimal oper1 = operStack.remove(0);
                BigDecimal res = compute(token, oper1, oper2);
                operStack.add(0, res);
            }
        }
        return operStack.remove(0);
    }
    private BigDecimal compute(String oper, BigDecimal op1, BigDecimal op2){
        if (oper.equals("/")){
            return op1.divide(op2);
        }
        else if (oper.equals("*")){
            return op1.multiply(op2);
        }
        else if (oper.equals("+")){
            return op1.add(op2);
        }
        else {
            return op1.subtract(op2);
        }
    }
}
