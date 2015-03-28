
<div class="container fin">
  <div class="col-xs-12 complex-menu zero-padding">
    <div class="col-xs-6">
				   <span>
				   	<?php print $logo;?>
				   </span>
      <h2 class="active-complex">
        <?php print $name;?>
      </h2>
    </div>
    <div class="col-xs-6 complex-right-menu zero-padding">
      <ul class="padding-left-0">
        <?php foreach($menu as $item):?>
          <?php print $item;?>
        <?php endforeach;?>
      </ul>
    </div>
  </div>
</div>