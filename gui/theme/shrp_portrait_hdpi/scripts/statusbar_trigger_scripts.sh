#!/sbin/sh
#epicX_locker
cat > /twres/cache/c_status_bar_h.xml <<EOF
<?xml version="1.0"?>
<recovery>
	<details>
		<resolution width="1080" height="1920"/>
		<author>Teamwin | epicX</author>
		<title>SKY HAWK RECOVERY PROJECT</title>
		<description>Sky_hawK_status_bar_handler</description>
		<preview>preview.png</preview>
		<themeversion>3</themeversion>
	</details>
	<variables>
		<variable name="c_battery_bar_triger" value="$battery_bar" persist="0"/>
		<variable name="c_status_bar_triger" value="$statusbar" persist="0"/>
		<variable name="c_battery_icon_triger" value="$b_icon" persist="0"/>
		<variable name="c_battery_portrait_icon_triger" value="$bp_icon" persist="0"/>
		<variable name="c_battery_circle_icon_triger" value="$bc_icon" persist="0"/>
		<variable name="c_battery_txt_triger" value="$battery_txt" persist="0"/>
		<variable name="c_time_txt_triger" value="$time_txt" persist="0"/>
		<variable name="c_rounded_corner_trigger" value="$r_c" persist="0"/>
		<variable name="c_rounded_corner_type_1" value="$r_c_type_1" persist="0"/>
		<variable name="c_rounded_corner_type_2" value="$r_c_type_2" persist="0"/>
		<variable name="c_rounded_corner_type_3" value="$r_c_type_3" persist="0"/>
		<variable name="c_dash_ico_default" value="$d_i_default" persist="0"/>
		<variable name="c_dash_ico_black" value="$d_i_black" persist="0"/>
		<variable name="c_dash_ico_white" value="$d_i_white" persist="0"/>
		<variable name="c_dash_ico_aex" value="$d_i_aex" persist="0"/>
		<variable name="c_nav_type_pie" value="$cnt_p" persist="0"/>
		<variable name="c_nav_type_samsung" value="$cnt_s" persist="0"/>
		<variable name="c_nav_type_nxt_bit" value="$cnt_n" persist="0"/>
		<variable name="c_nav_type_custom" value="$cnt_c" persist="0"/>
		<variable name="c_nav_bg" value="$cnb" persist="0"/>
		<variable name="c_white_bg" value="$cb_w" persist="0"/>
		<variable name="c_dark_bg" value="$cb_d" persist="0"/>
		<variable name="c_black_bg" value="$cb_b" persist="0"/>
		<variable name="c_midnightblue_bg" value="$cb_m" persist="0"/>
		<variable name="c_wetasphalt_bg" value="$cb_ww" persist="0"/>
		<variable name="c_text_color_black" value="$ctc_black" persist="0"/>
		<variable name="c_text_color_white" value="$ctc_white" persist="0"/>
		<variable name="c_text_color_blue" value="$ctc_blue" persist="0"/>
		<variable name="c_text_color_indigo" value="$ctc_indigo" persist="0"/>
		<variable name="c_text_color_brown" value="$ctc_brown" persist="0"/>
		<variable name="c_text_color_teal" value="$ctc_teal" persist="0"/>
		<variable name="c_text_color_orange" value="$ctc_orange" persist="0"/>
		<variable name="c_text_color_red" value="$ctc_red" persist="0"/>
		<variable name="c_text_color_rr" value="$ctc_rr" persist="0"/>
		<variable name="c_text_color_pink" value="$ctc_pink" persist="0"/>
		<variable name="c_text_color_rpink" value="$ctc_rpink" persist="0"/>
		<variable name="c_text_color_green" value="$ctc_green" persist="0"/>
		<variable name="c_text_color_cyan" value="$ctc_cyan" persist="0"/>
		<variable name="c_text_color_yellow" value="$ctc_yellow" persist="0"/>
		<variable name="c_text_color_purple" value="$ctc_purple" persist="0"/>
		<variable name="c_acc_color_black" value="$cac_black" persist="0"/>
		<variable name="c_acc_color_white" value="$cac_white" persist="0"/>
		<variable name="c_acc_color_blue" value="$cac_blue" persist="0"/>
		<variable name="c_acc_color_indigo" value="$cac_indigo" persist="0"/>
		<variable name="c_acc_color_brown" value="$cac_brown" persist="0"/>
		<variable name="c_acc_color_teal" value="$cac_teal" persist="0"/>
		<variable name="c_acc_color_orange" value="$cac_orange" persist="0"/>
		<variable name="c_acc_color_red" value="$cac_red" persist="0"/>
		<variable name="c_acc_color_rr" value="$cac_rr" persist="0"/>
		<variable name="c_acc_color_pink" value="$cac_pink" persist="0"/>
		<variable name="c_acc_color_rpink" value="$cac_rpink" persist="0"/>
		<variable name="c_acc_color_green" value="$cac_green" persist="0"/>
		<variable name="c_acc_color_cyan" value="$cac_cyan" persist="0"/>
		<variable name="c_acc_color_yellow" value="$cac_yellow" persist="0"/>
		<variable name="c_acc_color_purple" value="$cac_purple" persist="0"/>
		<variable name="c_notch_mode" value="$cnm" persist="0"/>
	</variables>
</recovery>
EOF
