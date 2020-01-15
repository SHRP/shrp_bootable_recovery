#!/sbin/sh
cat > /twres/cache/c_status_bar_h.xml <<EOF
<?xml version="1.0"?>
<recovery>
	<details>
		<resolution width="1080" height="1920"/>
		<author>Teamwin | epicX</author>
		<title>SKY HAWK RECOVERY PROJECT</title>
		<description>Sky_hawK_theme_handler</description>
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
		<variable name="c_rounded_corner_type" value="$r_c_type" persist="0"/>
		<variable name="c_dash_ico" value="$d_i" persist="0"/>
		<variable name="c_nav_type" value="$cnt" persist="0"/>
		<variable name="c_nav_bg" value="$cnb" persist="0"/>
		<variable name="c_bgc" value="$cb" persist="0"/>
		<variable name="c_text_color" value="$ctc" persist="0"/>
		<variable name="c_acc_color" value="$cac" persist="0"/>
		<variable name="c_notch_mode" value="$cnm" persist="0"/>
	</variables>
</recovery>
EOF
