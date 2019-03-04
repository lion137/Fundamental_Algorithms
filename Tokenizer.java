package rpn;

import java.util.Arrays;
import java.util.List;

public class Tokenizer {
    public List<String> tokenize(String exp){
        /*Take a string expression and returns a list of tokens; ex.:
        "(A + B -1)/ 3. 5" -> [(. A, +, B, -, 1, ), /, 3.5]
        */
        exp = exp.replace(" ", "");
        exp = exp.replace("+", " + ").replace("-", " - ").replace("/", " / ");
        exp = exp.replace("*", " * ");
        exp = exp.replace("(", " ( ").replace(")", " ) ").trim();
        List<String> exp_list = Arrays.asList(exp.split("\\s+"));
        return exp_list;
    }
}
