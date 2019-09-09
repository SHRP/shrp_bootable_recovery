#!/sbin/sh
#epicX_locker
cat > /twres/cache/shrp_lock_data_base.xml <<EOF
<?xml version="1.0"?>
<recovery>
	<details>
		<resolution width="1080" height="1920"/>
		<author>Teamwin | epicX</author>
		<title>SKY HAWK RECOVERY PROJECT</title>
		<description>Sky_hawK_lock_handler</description>
		<preview>preview.png</preview>
		<themeversion>3</themeversion>
	</details>
	<variables>
		<variable name="lock_enabled" value="$pass_lock_state"/>
		<variable name="patt_lock_enabled" value="$pattern_lock_state"/>
		<variable name="main_pass" value="$password"/>
		<variable name="c_new" value="$new"/>
		<variable name="c_new_pattern" value="$pattern"/>
	</variables>
</recovery>
EOF
