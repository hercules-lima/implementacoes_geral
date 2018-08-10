/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package brincs;

/**
 *
 * @author Douglas Costa
 */
public class FilaEncadeada <E> implements Fila{
    
    No inicio, fim;

    @Override
    public void add(Object novo) {
        E no = (E) novo;
        No aux = new No(no);
        if(isEmpty()){
            inicio = aux;
            fim = aux;
        }
        else{
            fim.setProx(aux);
            fim = aux;
        }
    }

    @Override
    public void imprime() {
        if(!isEmpty()){
            No aux = inicio;
            while(aux!=null){
                System.out.println(aux.GetE());
                aux = aux.getProx();
            }
        }
    }

    @Override
    public No remove() {
        No aux = inicio;
        if(!isEmpty()){
            if(inicio == fim){
                inicio = null;
                fim = null;
            }
            else{
                inicio = inicio.getProx();
            }
        }
        return aux;
    }

    @Override
    public boolean isEmpty() {
        return (inicio == null)? true : false;
    }
    
    public static void main(String[] args) {
        Fila f = new FilaEncadeada();
        String s = "douglas";
        String fs = "javeiro?";
        f.add(s);
        f.add(fs);
        f.imprime();
        f.remove();
        f.imprime();
        
    }
    
}
