
#include "Function_box.h"

// Graphix_calc
using Graphix_calc::Numbed_button;

// Graph_lib
using Graph_lib::In_box;
using Graph_lib::Out_box;
using Graph_lib::Point;

// utility
#include "../utility/constants.h"
using namespace Frontend_consts;

namespace Graphix_calc {

// да, конструктор перегружен, но лучше пусть это будет здесь, чем по несколько раз в Graphix_window

Function_box::Function_box(unsigned long long int box_index, void cb_draw_graph(void*, void*),
                           void cb_hide_graph(void*, void*), void cb_rem_func(void*, void*),
                           void cb_draw_der(void*, void*), void cb_hide_der(void*, void*))
    : Graph_lib::Widget{Point{0, func_box_h * pix_amount(box_index)}, func_box_w, func_box_h, "",
                        nullptr},
      // необходимо отступить расстояние, где находится "y = "
      in_box{
          new In_box{Point{in_box_lab_w, func_box_h * int(box_index)}, in_box_w, in_box_h, "y = "}},
      draw_button{new Numbed_button{Point{0, func_box_h * int(box_index) + in_box_h}, btn_w, btn_h,
                                    "Draw", cb_draw_graph}},
      hide_button{new Numbed_button{Point{btn_w + padding, func_box_h * int(box_index) + in_box_h},
                                    btn_w, btn_h, "Hide", cb_hide_graph}},
      rem_button{
          new Numbed_button{Point{(btn_w + padding) * 2, func_box_h * int(box_index) + in_box_h},
                            btn_w, btn_h, "Remove", cb_rem_func}},
      curr_der{
          new Out_box{Point{0, func_box_h * int(box_index) + in_box_h + btn_h}, btn_w, btn_h, ""}},
      draw_der_button{
          new Numbed_button{Point{btn_w + padding, func_box_h * int(box_index) + in_box_h + btn_h},
                            btn_w, btn_h, "Draw", cb_draw_der}},
      hide_der_button{new Numbed_button{
          Point{(btn_w + padding) * 2, func_box_h * int(box_index) + in_box_h + btn_h}, btn_w,
          btn_h, "Hide", cb_hide_der}},
      out_box{new Out_box{Point{0, func_box_h * int(box_index) + in_box_h + 2 * btn_h}, out_box_w,
                          out_box_h, ""}}
{
}

void Function_box::move(int dx, int dy)
{
    in_box->move(dx, dy);
    draw_button->move(dx, dy);
    hide_button->move(dx, dy);
    rem_button->move(dx, dy);
    curr_der->move(dx, dy);
    draw_der_button->move(dx, dy);
    hide_der_button->move(dx, dy);
    out_box->move(dx, dy);
}

void Function_box::set_message(const std::string& message) { out_box->put(message); }

void Function_box::set_index(int value)
{
    draw_button->set_number(value);
    hide_button->set_number(value);
    rem_button->set_number(value);
    draw_der_button->set_number(value);
    hide_der_button->set_number(value);
}

void Function_box::attach(Graph_lib::Window& win)
{
    // try to decomment this :)
    // win.attach(*this);
    win.attach(*in_box);
    win.attach(*draw_button);
    win.attach(*hide_button);
    win.attach(*rem_button);
    win.attach(*curr_der);
    win.attach(*draw_der_button);
    win.attach(*hide_der_button);
    win.attach(*out_box);
    own = &win;
}

void Function_box::detach(Graph_lib::Window& win)
{
    // try to decomment this :)
    // win.detach(*this);
    win.detach(*in_box);
    win.detach(*draw_button);
    win.detach(*hide_button);
    win.detach(*rem_button);
    win.detach(*curr_der);
    win.detach(*draw_der_button);
    win.detach(*hide_der_button);
    win.detach(*out_box);
    own = &win;
}

}  // namespace Graphix_calc