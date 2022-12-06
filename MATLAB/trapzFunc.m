function trapzFunc (expression, strips, xmin, xmax, ymin, ymax, zmin, zmax)
switch nargin
    case 4
        syms x
        exp = 0;
        h = (xmax-xmin)/strips;
        if (strips > 1)
            for i = 1:(strips-1)
                exp = exp + 2*(subs(expression, x, (xmin+(i*h))));
            end
        end
        exp1 = (xmax-xmin)*(subs(expression, x, xmin) + exp + subs(expression, x, xmax))/(2*strips);
        disp(exp1);
    case 6
        syms x y
        exp = 0;
        h = (xmax-xmin)/strips;
        if (strips > 1)
            for i = 1:(strips-1)
                exp = exp + 2*(subs(expression, x, (xmin+(i*h))));
            end
        end
        exp1 = (xmax-xmin)*(subs(expression, x, xmin) + exp + subs(expression, x, xmax))/(2*strips);
        disp(exp1);

        exp = 0;
        h = (ymax-ymin)/strips;
        if (strips > 1)
            for i = 1:(strips-1)
                exp = exp + 2*(subs(exp1, y, (ymin+(i*h))));
            end
        end
        exp2 = (ymax-ymin)*(subs(exp1, y, ymin) + exp + subs(exp1, y, ymax))/(2*strips);
        disp(exp2);
    case 8
        syms x y z
        exp = 0;
        h = (xmax-xmin)/strips;
        if (strips > 1)
            for i = 1:(strips-1)
                exp = exp + 2*(subs(expression, x, (xmin+(i*h))));
            end
        end
        exp1 = (xmax-xmin)*(subs(expression, x, xmin) + exp + subs(expression, x, xmax))/(2*strips);
        disp(exp1);

        exp = 0;
        h = (ymax-ymin)/strips;
        if (strips > 1)
            for i = 1:(strips-1)
                exp = exp + 2*(subs(exp1, y, (ymin+(i*h))));
            end
        end
        exp2 = (ymax-ymin)*(subs(exp1, y, ymin) + exp + subs(exp1, y, ymax))/(2*strips);
        disp(exp2);

        exp = 0;
        h = (zmax-zmin)/strips;
        if (strips > 1)
            for i = 1:(strips-1)
                exp = exp + 2*(subs(exp2, y, (zmin+(i*h))));
            end
        end
        exp3 = (zmax-zmin)*(subs(exp2, z, zmin) + exp + subs(exp2, z, zmax))/(2*strips);
        disp(exp3);
end
end