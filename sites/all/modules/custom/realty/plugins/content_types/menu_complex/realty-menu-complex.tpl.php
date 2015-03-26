<div class="container-fluid breadcrumb-line">
  <div class="container fin">
    <div class="col-xs-12 breadcrumb-block  margine-top">
      <ol class="breadcrumb zero-padding breadcrumbfix">
        <li><?php print $city?></li>
        <?php if(isset($page)):?>
          <li>
            <?php print $complex?>
          </li>
          <li class="active">
            <?php print $page?>
          </li>
          <?php endif;?>
        <?php if(!isset($page)):?>
          <li class="active">
            <?php print $complex?>
          </li>
        <?php endif;?>
      </ol>
    </div>
  </div>
</div>

<div class="container fin">
  <div class="col-xs-12 complex-menu zero-padding">
    <div class="col-xs-6">
				   <span>
             <?php if(isset($complex_mini_logo)):?>
                <?php print render($complex_mini_logo)?>
             <?php endif?>
				   </span>
      <h2 class="active-complex">
        <?php print render($title_complex)?>
      </h2>
    </div>
    <div class="col-xs-6 complex-right-menu zero-padding">
      <ul>
        <?php foreach($menu as $item):?>
          <?php print $item?>
        <?php endforeach?>
      </ul>
    </div>
  </div>
</div>