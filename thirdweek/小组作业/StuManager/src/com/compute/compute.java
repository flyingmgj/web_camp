package com.compute;

import java.io.IOException;
import java.util.Stack;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class compute
 */
@WebServlet("/compute")
public class compute extends HttpServlet {
	private static final long serialVersionUID = 1L;
	@Override
	protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		req.setCharacterEncoding("utf-8");
		resp.setContentType("text/html;charset=utf-8");
		//获取请求数据
		 String expression = req.getParameter("expression");
		//处理请求数据
		 computer cmp = new computer();
		 if(!cmp.check(expression)) { //表达式错误
			 //使用请求转发来返回数据
			 req.setAttribute("error", true);
			 req.getRequestDispatcher("/compute.jsp").forward(req, resp);;
			 System.out.println("表达式错误");
			 return ;
		 }
		 int result = cmp.caculate(expression);
		 req.setAttribute("result", result);
		 req.getRequestDispatcher("/compute.jsp").forward(req, resp);
		 System.out.println("计算结果为:"+result);
		 return;
	}
}

class computer {
	private Stack<Character> optStack = new Stack<Character>();// 操作符栈      
    private Stack<Integer> numStack = new Stack<Integer>();;// 操作数栈      
      
    /**   
     * 传入需要解析的字符串，返回计算结果
     * @param str 需要进行计算的表达式   
     * @return 计算结果   
     */      
    public int caculate(String str) {      	
        String temp;		// 用来临时存放读取的字符      
        		// 2.循环开始解析字符串，当字符串解析完，且符号栈为空时，则计算完成      
        StringBuffer tempNum = new StringBuffer();	// 用来临时存放数字字符串(当为多位数时)      
        StringBuffer string = new StringBuffer().append(str).append("#");// 用来保存，提高效率      
      
        while (string.length() != 0) {      
            temp = string.substring(0, 1);      
            string.delete(0, 1);      
            // 判断temp，当temp为操作符时      
            if (!isNum(temp)) {      
                // 1.此时的tempNum内即为需要操作的数，取出数，压栈，并且清空tempNum      
                if (!"".equals(tempNum.toString())) {      
                    // 当表达式的第一个符号为括号      
                    int num = Integer.parseInt(tempNum.toString());      
                    numStack.push(num);  
                    tempNum.delete(0, tempNum.length());      
                }      
                // 用当前取得的运算符与栈顶运算符比较优先级：若高于，则因为会先运算，放入栈顶；若等于，因为出现在后面，所以会后计算，所以栈顶元素出栈，取出操作数运算；      
                // 若小于，则同理，取出栈顶元素运算，将结果入操作数栈。      
      
                // 判断当前运算符与栈顶元素优先级，取出元素，进行计算(因为优先级可能小于栈顶元素，还小于第二个元素等等，需要用循环判断)      
                while (!compare(temp.charAt(0)) && (!optStack.empty())) {   
                    int a = (int) numStack.pop();// 第二个运算数      
                    int b = (int) numStack.pop();// 第一个运算数      
                    char ope = optStack.pop();      
                    int result = 0;// 运算结果      
                    switch (ope) {      
                    // 如果是加号或者减号，则      
                    case '+':      
                        result = b + a;      
                        // 将操作结果放入操作数栈      
                        numStack.push(result);      
                        break;      
                    case '-':      
                        result = b - a;      
                        // 将操作结果放入操作数栈      
                        numStack.push(result);      
                        break;      
                    case '*':      
                        result = b * a;      
                        // 将操作结果放入操作数栈      
                        numStack.push(result);      
                        break;      
                    case '/':      
                        result = b / a;// 将操作结果放入操作数栈      
                        numStack.push(result);      
                        break;      
                    }      
      
                }      
                // 判断当前运算符与栈顶元素优先级， 如果高，或者低于平，计算完后，将当前操作符号，放入操作符栈      
                if (temp.charAt(0) != '#') {      
                    optStack.push(new Character(temp.charAt(0)));      
                    if (temp.charAt(0) == ')') {// 当栈顶为'('，而当前元素为')'时，则是括号内以算完，去掉括号      
                        optStack.pop();      
                        optStack.pop();      
                    }      
                }      
            } else// 操作数                       
                tempNum = tempNum.append(temp);	//将读到的这一位数接到以读出的数后(当不是个位数的时候)      
        }      
        return numStack.pop();      
    }      
      
    /**   
     * 判断传入的字符是不是0-9的数字   
     *    
     * @param str   
     *            传入的字符串   
     * @return   
     */      
    private boolean isNum(String temp) {      
        return temp.matches("[0-9]");      
    }      
      
    /**   
     * 比较当前操作符与栈顶元素操作符优先级，如果比栈顶元素优先级高，则返回true，否则返回false   
     *    
     * @param str 需要进行比较的字符   
     * @return 比较结果 true代表比栈顶元素优先级高，false代表比栈顶元素优先级低   
     */      
    private boolean compare(char str) {      
        if (optStack.empty()) {      
            // 当为空时，显然 当前优先级最低，返回高      
            return true;      
        }      
        char last = (char) optStack.lastElement();      
        // 如果栈顶为'('显然，优先级最低，')'不可能为栈顶。      
        if (last == '(') {      
            return true;      
        }      
        switch (str) {      
        case '#':      
            return false;// 结束符      
        case '(':      
            // '('优先级最高,显然返回true      
            return true;      
        case ')':      
            // ')'优先级最低，      
            return false;      
        case '*': {      
            // '*/'优先级只比'+-'高      
            if (last == '+' || last == '-')      
                return true;      
            else      
                return false;      
        }      
        case '/': {      
            if (last == '+' || last == '-')      
                return true;      
            else      
                return false;      
        }      
            // '+-'为最低，一直返回false      
        case '+':      
            return false;      
        case '-':      
            return false;      
        }      
        return true;      
    }      
/*
 * 对传入的字符串进行格式检验
 */
    public boolean check(String str) {
    	if(str == null) return false;
    	int length = str.length();
        String temp; 
        int flag = 0 ;//用于计算左右括号是否匹配
        int i = 0;
        StringBuffer tempNum = new StringBuffer();	
        StringBuffer string = new StringBuffer().append(str);
    	while (i < length) {      
            temp = string.substring(i, i+1);
            i++;
           //首先要匹配到合适字符 
            if(!temp.matches("\\+|\\-|\\/|\\*|\\d|[()]")) {
            	return false;
            }else if(temp.matches("[0-9]")) { //数字直接跳过到下一个
            	continue;
            }else if(temp.matches("\\+|\\-|\\/|\\*")) {	//操作符+-/*则要判断下一个不能也是+-*/
            	if(i<length && (string.substring(0, 1)).matches("\\+|\\-|\\/|\\*") ) {
            		return false;
            	}
            }else if(temp.equals('(')) {	//左括号左边不能是数，右边不能是符号
            	if( i != 1 && string.substring(i-2,i-1).matches("[0-9]") || ( i <length && string.substring(i, i+1).matches("\\+|\\-|\\/|\\*"))) {
            		return false;
            	}
            	flag++;
            }else { //右括号左边不能是符号，右边不能是数
            	if( i != 1 && string.substring(i-2,i-1).matches("\\+|\\-|\\/|\\*") || ( i <length && string.substring(i, i+1).matches("[0-9]"))) {
            		return false;
            	}
            	flag--;
            }
    	}
    	if(flag != 0) {
    		return false ;
    	}
    	return true;
    }
/**
 *	优先级
 * @param ch---符号
 * @return 符号对应的优先级
 */
    private int priority(char ch) {
    	switch(ch)
    	{
    		case '(':
    			return 3;
    		case '*':
    		case '/':
    			return 2;
    		case '+':
    		case '-':
    			return 1;
    		default:
    			return 0;
    	}
    }
    public static void main(String args[]) {      
//        Operate operate = new Operate();      
//        int t = operate.caculate("(3+4*(4*10-10/2)#");        
//        System.out.println(t);      
    } 

}
